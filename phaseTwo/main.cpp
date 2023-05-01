#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FSTree.h"
#include "DirNode.h"
#include <sstream>
#include "hash_table_values.h"
#include "file.h"
#include "gerp.h"

using namespace std;

/* int main
* Purpose: responsible for creating an instance of the gerp object and running
* it with the input directory to the output file given by commandline arguments
* Parameters: int argc char*argv[]
* Returns: returns 0
* Effects: if there are not enough commands given by the commandline, cerr
* error message and exit accordingly
*/
int main (int argc, char* argv[]) {
    if( argc != 3) { 
        cerr << "Usage: ./gerp inputDirectory outputFile" << endl;
        return(EXIT_FAILURE);
    }
    string root = argv[1];
    string outputFile = argv[2];
    Gerp g = Gerp(root);
    g.run(outputFile);
    cout << "Goodbye! Thank you and have a nice day." << endl;
    return 0;

}