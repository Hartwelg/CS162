#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

//forward declare the class Character to prevent circular header dependency
class Character;
class Weapon: public Item
{
  private:
    std::string name;
    int value;
    int damage;
public:
    Weapon(std::string name, int damageValue, int cost);
    std::string getName();
    int getValue();
    std::string toString() override;
    int getDamage();
    virtual int getRange();
    virtual useOn(Character& target, int rangeToTarget);
};
#endif // WEAPON_H
