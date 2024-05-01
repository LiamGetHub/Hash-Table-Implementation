#include "Hashtable.h"
#include "Item.h"


Item::Item() {
  isDeleted = false;
  strVal = "";
}

// getters
std::string Item::getString() {
  return strVal;
}

bool Item::getIsDeleted() {
  return isDeleted;
}

// setters
void Item::setString(std::string str) {
  strVal = str;
}

void Item::setIsDeleted(bool isDelete) {
  isDeleted = isDelete;
}