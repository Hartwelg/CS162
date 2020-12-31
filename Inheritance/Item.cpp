#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string theName, int cost)
{
    name = theName;
    value = cost;
}
string Item::getName()
{
    return name;
}
int Item::getValue()
{
    return value;
}
string Item::toString()
{
    string description;
    description += getName();
    description += " (value: ";
    description += to_string(value);
    description += ")";
    return description;
}
