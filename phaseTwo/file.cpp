#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FSTree.h"
#include "DirNode.h"
#include <sstream>
#include "file.h"


using namespace std;


/* vector<vector<string<string>> make_file
* Purpose: places all of the files and their lines inside of the files 2Dvector
* Parameters: string root
* Returns: the 2D vector storing the files and the lines
* Effects: each file is represented by one vector of strings
*/
vector<vector<string>> file::make_file(string root) {
    fnames = filenames(root);
    vector<vector<string>> f;
    for(size_t i = 0; i < fnames.size(); i++) {
        f.push_back(save_files(fnames[i]));
    }
    return f;
}

/* vector<string> save_files
* Purpose: goes into the file, and saves each line to a string which is
* insertted into the files vector
* Parameters: string directory name
* Returns: the file lines all in a string a vectors
* Effects: none
*/
vector<string> file::save_files(string dir_name) {
    string line;
    ifstream input;
    input.open(dir_name);
    vector<string> file;
    while (getline(input, line)) {
        file.push_back(line);
    }
    input.close();
    return file;
}

/* void FSTreeTraversal
* Purpose: traverses the file tree and inserts the path to the back of the
* vector given back
* Parameters: starting node, starting directory string, vector of strings
* Returns: the modified vector of strings
* Effects: none
*/
void file::FSTreeTraversal(DirNode* node, string start, vector<string> &v) {
    if (node->hasFiles()) {
        for (int i = 0; i < node->numFiles(); ++i) {
            string path = start + "/" + node->getFile(i);
            v.push_back(path);
        }
    }
    if (node->hasSubDir()) {
        for (int i = 0; i < node->numSubDirs(); ++i) {
            FSTreeTraversal(node->getSubDir(i), start + "/" + 
            node->getSubDir(i)->getName(), v);
        }
    }
}

/* vector<string> filenames
* Purpose: gets all of the file paths and stores them in a vector of strings
* Parameters: string of the root directory
* Returns: the vector of file paths
* Effects: none
*/
vector<string> file::filenames(string root) {
    try {
        FSTree f(root);
        string start = f.getRoot()->getName();
        vector<string> filepaths;
        FSTreeTraversal(f.getRoot(), start, filepaths);
        return filepaths;
    }
    catch(exception &e) {
        cerr << "Could not build index, exiting." << endl;
        exit(EXIT_FAILURE);
        
    }
}
