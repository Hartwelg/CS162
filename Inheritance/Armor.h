#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
class Armor: public Item
{
  private:
    std::string name;
    int value;
    int protection;
public:
    Armor(std::string theName, int protectionValue, int cost);
    std::string getName();
    int getValue();
    std::string toString() override;
    int getProtection();
};
#endif // ARMOR_H
