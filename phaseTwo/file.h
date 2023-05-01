#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FSTree.h"
#include "DirNode.h"
#include <sstream>


using namespace std;

class file {
    public:
        vector<vector<string>> make_file(string dir_name);
        vector<string> filenames(string root);
        
        //void filenames(string root);
        
    private:
        vector<string> save_files(string dir_name);
        //void FSTreeTraversal(DirNode *root, string s, ostringstream &output);
        void FSTreeTraversal(DirNode* node, string start, vector<string> &v);
        //void FSTreeTraversal(DirNode *root, string path, vector<string> &v);
       // void FSTreeTraversal(DirNode *root, string s, vector<string> &v);
        //void FSTreeTraversal(DirNode *root, string s);
        vector<string> fnames;

};


#endif