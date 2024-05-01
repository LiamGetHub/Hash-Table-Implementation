#include <iostream>
#include "cmath"

#include "Item.h"
#include "Hashtable.h"
using namespace std;



int main() {
  HashTable hashtable;
  hashtable.printTable();

  std::cout << "--------------" << std::endl;
  
  hashtable.insert("five");
  hashtable.insert("four");
  hashtable.insert("six");
  hashtable.insert("seven");
  
  hashtable.insert("nine");
  hashtable.insert("two");
  hashtable.insert("one");
  hashtable.insert("three");
  hashtable.insert("eight");

  hashtable.insert("ten");
  hashtable.insert("eleven");
  hashtable.insert("twelve");
  hashtable.insert("thirteen");
  hashtable.insert("fourteen");

  hashtable.insert("fifthteen");
  hashtable.insert("sixteen");
  hashtable.insert("seventeen");
  hashtable.insert("eightteen");
  hashtable.insert("nineteen");
  hashtable.insert("twenty");
  hashtable.insert("twentyone");
  hashtable.insert("twentytwo");
  hashtable.insert("twentythree");
  hashtable.insert("twentyfour");
  
  
  std::cout << "--------------" << std::endl;
  
  hashtable.printTable();
  std::cout << "Item count: " << hashtable.getItemCount() << std::endl;
  std::cout << "Table size: " << hashtable.getTableSize() << std::endl;
  std::cout << "Load Factor: " << hashtable.getLoadFactor() << std::endl;
  
  if (hashtable.search("ten") == true) {
    std::cout << "Found" << std::endl;
  }
  else {
    std::cout << "Not found" << std::endl;

  }
}
