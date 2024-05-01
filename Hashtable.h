#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>

//using namespace std;

class HashTable {

  public:
    HashTable();

    void insert(std::string str);

    void printTable();

    int hashFunction(std::string, int);

    unsigned int hash(std::string);

    void rehash();

    bool search(std::string str);

    

    int getItemCount();
    int getTableSize();
    double getLoadFactor();

  private:

    int itemCount;
    int tableSize;
    double loadFactor;

    std::vector<std::string> * table;

};




#endif
