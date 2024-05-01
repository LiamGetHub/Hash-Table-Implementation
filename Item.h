#ifndef ITEM_H
#define ITEM_H

#include "Hashtable.h"


class Item {

  public:

    Item();

    std::string getString();

    bool getIsDeleted();
    
    void setString(std::string str);

    void setIsDeleted(bool isDelete);


  private:
    
    std::string strVal;

    bool isDeleted;

};

#endif