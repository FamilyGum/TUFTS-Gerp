#include "FSTree.h"
#include "DirNode.h"
#include <string>
#include <iostream>

using namespace std;

void FSTreeTraversal(DirNode *root, string s);

int main (int argc, char *argv[]){
    
    if (argc < 2){
        exit(EXIT_FAILURE);
    }
    FSTree f(argv[1]);
    string start = "";
    FSTreeTraversal(f.getRoot(), start);
    
    
    return 0;
}

void FSTreeTraversal(DirNode *root, string s){
    if (root == nullptr){
        return;
    }
    else {
        if (root->hasFiles()){
            for(int i = 0; i < root->numFiles(); i++){
                cout << s << root->getName() << "/" << root->getFile(i) << endl;
            }
        }
        if (root->hasSubDir()){
            for(int i = 0; i < root->numSubDirs(); i++){
                FSTreeTraversal(root->getSubDir(i), s + root->getName() + "/");
            }
        }
    }
}
