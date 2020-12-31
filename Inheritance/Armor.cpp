#include "Armor.h"

using namespace std;

Armor::Armor(string theName, int protectionValue, int cost)
    : Item::Item(theName, cost)
{
    protection = protectionValue;
}
string Armor::getName()
{
    return Item::getName();
}
int Armor::getValue()
{
  return Item::getValue();
}
string Armor::toString()
{
    string description;
    description += Item::toString();
    description += " Protection: ";
    description += to_string(protection);
    return description;
}
int Armor::getProtection()
{
    return protection;
}
