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


//tests for file.cpp

/*
this should print all the files and their paths in a given
directory
for tinyData it should print
/comp/15/files/proj4-test-dirs/tinyData/a/found
/comp/15/files/proj4-test-dirs/tinyData/a/you
/comp/15/files/proj4-test-dirs/tinyData/b/hehe.txt
/comp/15/files/proj4-test-dirs/tinyData/b/c/heyLookAtMe.txt
/comp/15/files/proj4-test-dirs/tinyData/b/c/me
/comp/15/files/proj4-test-dirs/tinyData/hello
/comp/15/files/proj4-test-dirs/tinyData/test.txt
*/
void test_tree_traversal() {
    string root = "/comp/15/files/proj4-test-dirs/tinyData";
    FSTree f(root);
    string start = f.getRoot()->getName();
    vector<string> filepaths;
    FSTreeTraversal(f.getRoot(), start, filepaths);
    //inspection check
    for(string s : filepaths) {
        cout << s << endl;
    }
}

/*
this should print all the files and their paths in a given
directory
for tinyData it should print, very  similar to FSTree traversal
/comp/15/files/proj4-test-dirs/tinyData/a/found
/comp/15/files/proj4-test-dirs/tinyData/a/you
/comp/15/files/proj4-test-dirs/tinyData/b/hehe.txt
/comp/15/files/proj4-test-dirs/tinyData/b/c/heyLookAtMe.txt
/comp/15/files/proj4-test-dirs/tinyData/b/c/me
/comp/15/files/proj4-test-dirs/tinyData/hello
/comp/15/files/proj4-test-dirs/tinyData/test.txt
*/
void test_filenames() {
    vector<string> fnames = 
    filenames("/comp/15/files/proj4-test-dirs/tinyData");
    for(string s : fnames) {
        cout << s << endl;
        //test by inspection
    }
}

/*
this should print all the lines of the file given
for test it should print
djnfvb 
lkfbngfb lfgjnfg
dlfjn gflfjnflgb dlgkjn
ldfjnkb 
dgljfn dlfjgn
ldjng dlfgnb dljfsjv dfjg
*/
void test_file_saving() {
    vector<string> test = 
    save_files("/h/ktripa01/cs15/final-proj/test/test2.txt")
    for(string line : test) {
        cout << line << endl;
    }
    //test by comparing to the file
}

//tests for hash_table_values.cpp

//test insertion and retrival from a hashmap
//assert the values are what we set them to be
/*
line:
a - 1
b - 3
c - 4
file:
a - 2
b - 4
c - 5
*/
void hash_insert_and_get() {
    HashTableV hv = HashTableV();
    hv.insert("a", Value(1, 2));
    hv.insert("b", Value(3, 4));
    hv.insert("c", Value(4, 5));
    assert(hv.get("a")->values[0].file == 1);
    assert(hv.get("a")->values[0].line == 2);
    assert(hv.get("b")->values[0].file == 3);
    assert(hv.get("b")->values[0].line == 4);
    assert(hv.get("c")->values[0].file == 4);
    assert(hv.get("c")->values[0].line == 5);
}

//test insertion and retrival from a hashmap
// with one key having multiple values
/*
assertion:
line:
a - 1, 2, 3
file:
a - 4, 5, 6
*/
void hash_insert_many() {
    HashTableV hv = HashTableV();
    hv.insert("a", Value(1, 4));
    hv.insert("a", Value(2, 5));
    hv.insert("a", Value(3, 6));
    int size = hv.get("a")->values.size();
    for(int i = 0; i < size; i++) {
        assert(hv.get("a")->values[i].file == 1+i);
        assert(hv.get("a")->values[i].line == 4+i);
    }
}

//test hash function on same key
//assert should be true
void hashv_test_same() {
    HashTableV hv = HashTableV();
    assert(hashV("a") == hashV("a"));
}

//test hash function on different key
//assert should be false
void hashv_test_different() {
    HashTableV hv = HashTableV();
    assert(hashV("a") != hashV("b"));
}

//test rehash function on a hashtable with a small capacity
void test_rehash() {
    //set hashGroup to 1 for this
    HashTableV hv = HashTableV();
    hv.insert("a", Value(1, 4));
    hv.rehash();
    assert(hv.get("a")->values[i].file == 1);
    assert(hv.get("a")->values[i].line == 4);
}
/*
this should output 1, 4 and 2, 5
testing insensitive should bring both a and A
*/
void test_insensitive_search() {
    HashTableV hv = HashTableV();
    hv.insert("a", Value(1, 4));
    hv.insert("A", Value(2, 5));
    ChainNodeEntry *entry = hv.get("a")
    for(ChainNodeEntry *entry : entries){
        for(Value v : entry->values){
            cout << v.line << " " << v.file << endl;
        }
    }
    
    //check to make sure both A and a are in there
}

//tests for gerp

/*
NOTE: WE DONT NEED TO TEST EMPTY STRINGS BECAUSE WE MAKE SURE THE QUERY ARE
NEVER ATTEMPTED ON WITH EMPTY STRING
*/

/*
testing hash fill and query
should output
The the gjkfkdgjlfknld
The the gjkfkdgjlfknld
*/
void test_fill_hash() {
    Gerp g = Gerp("/h/ktripa01/cs15/final-proj/test");
    g.fill_hash();
    hv.query("the", cout);
    hv.query("The", cout);
    //visual check
}

/*
testing hash fill and query
should output
The the gjkfkdgjlfknld
The the gjkfkdgjlfknld
*/
void test_query() {
    Gerp g = Gerp("/h/ktripa01/cs15/final-proj/test");
    g.fill_hash();
    hv.query("gjkfkdgjlfknld", cout);
    //visual check
}

/*
testing hash fill and query
should output
The the gjkfkdgjlfknld
the gjfgl
*/
void test_iquery() {
    Gerp g = Gerp("/h/ktripa01/cs15/final-proj/test");
    g.fill_hash();
    hv.iquery("the", cout);
    //visual check
}

/*
testing hash fill and query
should output
The the gjkfkdgjlfknld
*/
void test_iquery_empty() {
    Gerp g = Gerp("/h/ktripa01/cs15/final-proj/test");
    g.fill_hash();
    hv.iquery("The", cout);
    //visual check
}

/*
testing hash fill and query
should output nothing, even though we dont need to test
we did incase
*/
void test_query_empty() {
    Gerp g = Gerp("/h/ktripa01/cs15/final-proj/test");
    g.fill_hash();
    hv.query("", cout);
    //visual check
}
