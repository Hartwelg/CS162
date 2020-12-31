#include "Weapon.h"

//Now include the full Character.h so we can call Character's functions
#include "Character.h"

Weapon::Weapon(std::string theName, int damageValue, int cost)
    :Item::Item(theName, cost)
{
    damage = damageValue;
}
std::string Weapon::getName()
{
    return Item::getName();
}
int Weapon::getValue()
{
    return Item::getValue();
}
std::string Weapon::toString()
{
    std::string description;
    description += Item::toString();
    description += " Damage: ";
    description += std::to_string(damage);
    return description;
}
int Weapon::getDamage()
{
    return damage;
}
int Weapon::getRange()
{
    return 0;
}
Weapon::useOn(Character& target, int rangeToTarget)
{
    if (rangeToTarget <= getRange())
    {
        target.takeDamage(damage);
    }
    else
    {
        return 0;
    }
}
