#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <string.h>
#include <functional>
#include <stack>
#include "hash_table_values.h"

using namespace std;

/* default constructor
* Purpose: creates an default instance of the HashTableV class
* Parameters: none
* Returns: none
* Effects: initializes the chainedtable and iniitalizes the nodes to nullptr
* also sets the current number of items to 0
*/
HashTableV::HashTableV()
{
    chainedTable = new ChainNodeEntry *[hashGroups];
    currentTableSize = hashGroups;
    numItemsInTable = 0;
    for (int i = 0; i < hashGroups; i++){
        chainedTable[i] = nullptr; // initialize to nullptr
    }
}


/* destructor for the HashTableV class
* Purpose: deletes all of the heap memory that is in the HashTable
* Parameters: none
* Returns: none
* Effects: none
*/
HashTableV::~HashTableV(){
    for (int i = 0; i < currentTableSize; ++i) {
        ChainNodeEntry *CNE = chainedTable[i];
        while (CNE) {
            ChainNodeEntry *next = CNE->next;
            delete CNE;
            CNE = next;
        }
    }
    delete[] chainedTable;
}

/* void hashV
* Purpose: returns the hash value for a specific query
* Parameters: string for the query
* Returns: the hash value
* Effects: none
*/
size_t HashTableV::hashV(string Query){
    for (size_t i = 0; i < Query.size(); i++){
        Query[i] = tolower(Query[i]);
    }
    return hash<string>{}(Query);

}

/* ChainNodeEntry *get
* Purpose: gets the chain node that corresponds to the given key
* Parameters: string key
* Returns: none
* Effects: will return nullptr if the node is not found
*/
ChainNodeEntry *HashTableV::get(string key){
    ChainNodeEntry *CNE = chainedTable[hashV(key) % currentTableSize];
    if (CNE == nullptr) return nullptr;
    while (CNE != nullptr){
        if(CNE->key == key){
            return CNE;
        }
        CNE = CNE->next; // add this line to move to the next node in the chain
    }
    return nullptr;
}

/* void insert
* Purpose: inserts the given key and the value corresponding into the Hash 
* Table
* Parameters: string key, and the value corresponding
* Returns: none
* Effects: if the value is not in the Hash Table, create a new node and insert
* the value in that node, put the node into the Hash Table. Also when the load
* of the table is above 70 percent of the table's capacity, will call the 
* rehash function
*/
void HashTableV::insert(string key, Value value){
    ChainNodeEntry *CNE = get(key); 
    if (CNE == nullptr) {
        double load = (double)numItemsInTable / currentTableSize;
        if (load >= 0.7){
            rehash();
        }
        ChainNodeEntry *node = 
        new ChainNodeEntry {key, vector<Value>{}, nullptr};
        node->values.push_back(value);
        int index = hashV(node->key) % currentTableSize;
        if (chainedTable[index] == nullptr) {
            chainedTable[index] = node;
        }
        else {
            node->next = chainedTable[index];
            chainedTable[index] = node;
        }
        numItemsInTable++;
        return;
    }
    else{
        if (not CNE->values.empty()) {
            if (CNE->values.back() != value){
                CNE->values.push_back(value);
            }
        }
        else {
            CNE->values.push_back(value);
            
        }
        
    }
}

/* void rehash
* Purpose: expands the Hash table and rehashes all of the nodes, puts them 
* their new coressponding hash index
* Parameters: none
* Returns: none
* Effects: will double the array size.
*/
void HashTableV::rehash() {
    int newSize = currentTableSize * 2;
    ChainNodeEntry** newChainedTable = new ChainNodeEntry*[newSize];
    for (int i = 0; i < newSize; i++) {
        newChainedTable[i] = nullptr;
    }
    for (int i = 0; i < currentTableSize; i++) {
        ChainNodeEntry *curr = chainedTable[i];
        while (curr != nullptr) {
            ChainNodeEntry *next = curr->next;
            curr->next = nullptr;
            int index = hashV(curr->key) % newSize;
            if (newChainedTable[index] == nullptr) {
                newChainedTable[index] = curr;
            }
            else {
                curr->next = newChainedTable[index];
                newChainedTable[index] = curr;
            }
            curr = next;
        }
    }
    delete[] chainedTable;
    chainedTable = newChainedTable;
    currentTableSize = newSize;
}

/* vector <ChainNodeEntry*> insensitiveSearchValues
* Purpose: gets the keys that match the lowercase version of the query
* Parameters: query string
* Returns: vector of all of teh nodes that match the lowercase version of key
* Effects: none
*/
vector<ChainNodeEntry*> HashTableV::insensitiveSearchValues(string Query) {
    vector<ChainNodeEntry*> insensitive;
    for (size_t i = 0; i < Query.size(); i++){
        Query[i] = tolower(Query[i]);
    }
    int index = hashV(Query) % currentTableSize;
    ChainNodeEntry *CNE = chainedTable[index];
    while (CNE != nullptr) {
        string key = CNE->key;
        for (size_t i = 0; i < key.size(); i++){
            key[i] = tolower(key[i]);
        }
        if (key == Query){
            insensitive.push_back(CNE);
        }
        CNE = CNE->next;
    }
    return insensitive;
}
