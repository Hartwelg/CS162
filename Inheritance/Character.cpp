#include <iostream>
#include <cassert>


#include "Character.h"

using namespace std;


Character::Character(const std::string& nameVal)
{
    name = nameVal;
    healthPoints = 100;


    weapon = new Weapon("Bare Hands", 1, 0);
    armor = new Armor("Skin", 0, 0);
}

void Character::print() const
{
    cout << name << endl;
    cout << "Health: " << healthPoints << endl;
    cout << "Armor: " << armor->toString() << endl;
    cout << "Weapon: " << weapon->toString() << endl;
    cout << "Inventory: " << endl;
    cout << "-----------------------------------" << endl;
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] != nullptr) {
            cout << "[" << i << "] " << inventory[i]->toString() << endl;
        }
    }
    cout << "-----------------------------------" << endl;
}


int Character::getHealthPoints() const
{
    return healthPoints;
}

void Character::takeDamage(int amount)
{
    if (armor->getProtection() >= amount)
    {
        healthPoints -= 0;
    }
    else
    {
        amount -= armor->getProtection();
        healthPoints -= amount;
    }
}

void Character::attack(Character& target, int range)
{
    weapon->useOn(target, range);
}

bool Character::aquire(Item* item)
{
    for(int i = 0; i < INVENTORY_SIZE; i++) {
        if(inventory[i] == nullptr) {
            inventory[i] = item;
            return true;
        }
    }
    return false;
}

void Character::equip(int itemNumber)
{
    if (inventory[itemNumber] == nullptr)
    {
        cout << "Nope";
    }
    else
    {
        if(dynamic_cast<Weapon*>(inventory[itemNumber]) != nullptr)//weapon
        {
            weapon = dynamic_cast<Weapon*>(inventory[itemNumber]);
        }
        else if (dynamic_cast<Armor*>(inventory[itemNumber]) != nullptr)//armor
        {
            armor = dynamic_cast<Armor*>(inventory[itemNumber]);
        }
    }
}

Weapon* Character::getWeapon()
{
    return weapon;
}

Armor* Character::getArmor()
{
    return armor;
}
