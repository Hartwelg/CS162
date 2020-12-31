#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(std::string theName, int damageValue, int rangeValue, int ammoValue, int cost)
    : Weapon::Weapon(theName, damageValue, cost)
{
    range = rangeValue;
    ammo = ammoValue;
}
std::string RangedWeapon::getName()
{
    return Weapon::getName();
}
int RangedWeapon::getValue()
{
    return Weapon::getValue();
}
std::string RangedWeapon::toString()
{
    std::string description;
    description += Weapon::toString();
    description += " Ammo: ";
    description += std::to_string(ammo);
    description += " Range: ";
    description += std::to_string(range);
    return description;
}
int RangedWeapon::getDamage()
{
    return Weapon::getDamage();
}
int RangedWeapon::getRange()
{
    return range;
}
RangedWeapon::useOn(Character& target, int rangeToTarget)
{
    if(ammo > 0)
    {
        ammo -= 1;
        Weapon::useOn(target, rangeToTarget);
    }
    else
    {
        return 0;
    }
}
int RangedWeapon::getAmmo()
{
    return ammo;
}
