#include "Hashtable.h"
#include "cmath"






//constructor
HashTable::HashTable() {
  tableSize = 13;
  itemCount = 0;
  loadFactor = 0.0;

  //initailize vecot to table size 13
  table = new std::vector<std::string>(tableSize);
}


void HashTable::printTable(){
  for (int i = 0; i < tableSize; i++) {
    std::cout << "[" << i << " | " << table->at(i) << "]" << std::endl;
  }
}

void HashTable::insert(std::string str){
  //h(x) = (hash(x) + f(i)) % tableSize
  //f(i) = i squared
  // pow(i,2)
  
  int i = 0;
  int location = hashFunction(str, i);

  //check to see what is in there
  while (table->at(location) != ""){    //while spot im looking at is not avalible
    location = hashFunction(str, i++);
    
  }
    table->at(location) = str;

    //update information
    itemCount++;
    loadFactor = (double)itemCount / tableSize;

  if (loadFactor > 0.5){
    rehash();
  }
  
}



// Function that returns true if n 
// is prime else returns false 
bool isPrime(int n) { 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 

    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 

    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 

    return true; 
} 

// Function to return the smallest
// prime number greater than N
int nextPrime(int N) {

    // Base case
    if (N <= 1)
        return 2;

    int prime = N;
    bool found = false;

    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}



void HashTable::rehash(){
  // note: isPrime and nextPrime foun from https://www.geeksforgeeks.org/program-to-find-the-next-prime-number
  
  std::vector<std::string> tempTable;

  //copying elements from old table to temp table, so we can add them back later
  for (int i = 0; i < (tableSize); i++) {
    while (table->at(i) == " ") {
      std::cout << i << std::endl;
      i++;
    }
    tempTable.push_back((*table)[i]);
  }
  
  //clears table, size is 0
  table->clear();

  // update table size to og table size * 2 then going to the next linear prime
  tableSize = nextPrime(tableSize);
  table->resize(tableSize);
  
  //loop goes through temptable (basically a copy of old table) and re inserts them into new table
  for (int j = 0; j < (tempTable.size()); j++) {
    std::string str = (tempTable)[j];
    int i = 0;
    int location = hashFunction(str, i);
    
    //check to see what is in there
    while (table->at(location) != ""){    //while spot im looking at is not avalible
      location = hashFunction(str, i++);
    }
      table->at(location) = str;

      //update information
      //itemCount++;
      loadFactor = (double)itemCount / tableSize;
  }
  
}




int HashTable::hashFunction(std::string str, int i) {
  // h(x)
  return (hash(str) + (int)pow(i, 2)) % tableSize;    // quadratic probing
  //return (hash(str) + i) % tableSize;               //linear probing
  
}



unsigned int HashTable::hash(std::string str) {
  unsigned int hashVal = 0;
  for (char ch : str){
    hashVal = 37 * hashVal + ch;
  }
  return hashVal;
}






bool HashTable::search(std::string str) {
  unsigned int hashVal = 0;
  int indexLocation;
  
  //stores numerical value in hashVal
  hashVal = hash(str);

  indexLocation = hashVal % tableSize;

  
  bool found = false;
  std::cout << "DEBUG: index location: " << indexLocation << std::endl;
  std::cout << "DEBUG: index table at location: " << (*table)[indexLocation] << std::endl;
  
  while (found == false && (*table)[indexLocation] != "") {
    if ((*table)[indexLocation] == str) {
      found = true;
      return found;
    }
    indexLocation++;
  }
  return found;
}






//getter functions so we can publically retrive but not modify the private information
int HashTable::getItemCount(){
  return itemCount;
}
int HashTable::getTableSize() {
  return tableSize;
}
double HashTable::getLoadFactor() {
  return loadFactor;
}

