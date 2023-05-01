#include "gerp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "hash_table_values.h"
#include "stringProcessing.h"
#include <set>
using namespace std;

/* Constructor for Gerp
* Purpose: responsible for creating an instance of the gerp class
* Parameters: a string root for the root directory
* Returns: none
* Effects: this constructor will also fill the files vector and it will fill 
* hash table with all of the words in the files
*/
Gerp::Gerp(string root) {
    f = file();
    files = f.make_file(root);
    fill_hash();
    fnames = f.filenames(root);
}

/* void fill_hash
* Purpose: will take every word in each of the files and inserts them into the
* hash table
* Parameters: none
* Returns: none
* Effects: will strip all of the punctuation off of the word it inserts
*/
void Gerp::fill_hash() {
    string word;
    for (size_t i = 0; i < files.size(); i++) { 
        for (size_t j = 0; j < files[i].size(); j++) {
            stringstream ss(files[i][j]);
            while (ss >> word) {
                //insert into hash table
                Value v(i, j);
                hash.insert(stripNonAlphaNum(word), v);
                
            }
        }
    }
}

/* void query
* Purpose: responsible for the executing the sensitive query
* Parameters: ofstream output object and query string
* Returns: none
* Effects: if the query is found, it will print the file path and line
* to the output stream, if it is not, it will output the proper not 
* found message
*/

void Gerp::query(string q, ofstream &output) {
    ChainNodeEntry *e = hash.get(q);
    if (e == nullptr or stripNonAlphaNum(q) == "") {
        output << q << " Not Found. Try with @insensitive or @i." << endl;
        return;
    }
    for (size_t i = 0; i < e->values.size(); i++) {
        output << fnames[e->values[i].file] << ":" << e->values[i].line + 1
        << ": " << files[e->values[i].file][e->values[i].line] << endl;
    }
}



/* void iquery
* Purpose: responsible for the insensitive query
* Parameters: string query and ofstream output object
* Returns: none
* Effects: takes all of the keys that have matching with the lowercase version
* of the query and outputs their values to the output stream
*/
void Gerp::iquery(string q, ofstream &output) {
    string prev = "";
    set<string> outted;
    vector<ChainNodeEntry*> entries = hash.insensitiveSearchValues(q);
    if (entries.empty() or stripNonAlphaNum(q) == "") {
        output << q << " Not Found." << endl;
        return;
    }
    for (ChainNodeEntry *entry : entries){
        for (Value v : entry->values){
            string out = fnames[v.file] + ":" + to_string(v.line + 1) + ": " 
            + files[v.file][v.line];
            outted.insert(out);
        }
    }
    for(string s : outted) {
        output << s << endl;
    }
}

/* void run
* Purpose: responsible for querying for user input until the user quits
* Parameters: output file string
* Returns: none
* Effects: responsible for opening the output file for the query functions and
* also is responsible for opening and closing the file in the @f function
*/
void Gerp::run(string outputFile){
    string cmd; 
    ofstream output;
    output.open(outputFile);
    cout << "Query? ";
    while(cin >> cmd) {
        if(cmd == "@q" or cmd == "@quit" or cin.eof()) return; //fix
        else if(cmd == "@i" or cmd == "@insensitive") {
           cin >> cmd;
           string stripper = stripNonAlphaNum(cmd);
           iquery(stripper, output);
        }
        else if(cmd == "@f"){
            cin >> cmd;
            output.close();
            output.open(cmd);
        }
        else {
            string stripper = stripNonAlphaNum(cmd);
            query(stripper, output);
        }
        cout << "Query? ";
    }
    output.close();
}


