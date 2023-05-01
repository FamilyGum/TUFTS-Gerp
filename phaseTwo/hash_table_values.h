#ifndef HASH_TABLE_VALUES_H
#define HASH_TABLE_VALUES_H
#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

struct Value {
    Value (int filenum, int linenum) {
        file = filenum;
        line = linenum;
    }
    int file; // file path
    int line;
    bool operator == (Value &other) {
        return file == other.file and line == other.line;
    }
    bool operator != (Value &other) {
        return file != other.file or line != other.line;
    }
};

struct ChainNodeEntry {
    ChainNodeEntry(string k, vector<Value> v, ChainNodeEntry *n){
        key = k;
        values = v;
        next = n;
    }
    string key;
    vector<Value> values;
    ChainNodeEntry *next;
    ~ChainNodeEntry() {
        values.clear();
    } 
};

class HashTableV {
    public: 
    HashTableV();
    ~HashTableV();
    void insert(string key, Value value);
    ChainNodeEntry *get(string key);
    vector<ChainNodeEntry*> insensitiveSearchValues(string Query);
    ChainNodeEntry **chainedTable;
    
    private: 
    static const int hashGroups = 1;
    size_t hashV(string lowerCaseQuery);
    int currentTableSize;
    int numItemsInTable;

    void rehash();
    
};
#endif