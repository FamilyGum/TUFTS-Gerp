#include "hash_table_values.h"
#include <iostream>
#include <vector>
#include <string>
#include "file.h"
#include "FSTree.h"
#include "DirNode.h"

class Gerp {
    public:
        Gerp(string root);
        void run(string outputFile);
        
    private:
        HashTableV hash = HashTableV();
        vector<vector<string>> files;
        string root; //root dir
        void fill_hash();
        file f;
        vector<string> fnames;
        void query(string q, ofstream &output);
        void iquery(string q, ofstream &output);
};