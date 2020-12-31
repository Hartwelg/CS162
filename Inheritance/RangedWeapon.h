#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "Weapon.h"
class RangedWeapon: public Weapon
{
  private:
    std::string name;
    int value;
    int damage;
    int range;
    int ammo;
public:
    RangedWeapon(std::string name, int damageValue, int rangeValue, int ammoValue, int cost);
    std::string getName();
    int getValue();
    std::string toString();
    int getDamage();
    int getRange() override;
    useOn(Character &target, int rangeToTarget) override;
    int getAmmo();
};
#endif // RANGEDWEAPON_H
