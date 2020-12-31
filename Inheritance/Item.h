#ifndef ITEM_H
#define ITEM_H

#include <string>
class Item
{
  private:
    std::string name;
    int value;
public:
    Item(std::string theName, int cost);
    std::string getName();
    int getValue();
    virtual std::string toString();
};

#endif // ITEM_H
