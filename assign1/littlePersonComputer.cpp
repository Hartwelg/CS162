/**
  * @author Gauge Hartwell
  * @brief assignment 1
  **/
#include <iostream>
#include <littlePersonComputer.h>

using namespace std;

LittlePersonComputer::LittlePersonComputer()
{
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < 20; i++)
    {
        memory[i] = 0;
    }
}
LittlePersonComputer::LittlePersonComputer(int instructions[], int numberOfInstructions)
{
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < numberOfInstructions; i++)
    {
        memory[i] = instructions[i];
    }
}
LittlePersonComputer::restart()
{
    accumulator = 0;
    programCounter = 0;
}
LittlePersonComputer::reset()
{
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < 20; i++)
    {
        memory[i] = {0};
    }
}
LittlePersonComputer::loadProgram(int instructions[], int numberOfInstructions)
{
    for (int i = 0; i < numberOfInstructions; i++)
    {
        memory[i] = instructions[i];
    }
}
LittlePersonComputer::printState()
{
    cout << "Accumulator: " << accumulator << "\tProgram Counter: " << programCounter << endl;
    cout << "Memory: " << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << left << setw(5) << i;
    }
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << left << setw(5) << memory[i];
    }
    cout << endl;
}
int LittlePersonComputer::getCurrentInstruction()
{
    return memory[programCounter];
}
LittlePersonComputer::step()
{
    int address;
    accumulator = memory[programCounter];

    if (accumulator / 100 == 0)
    {
        programCounter ++;
    }
    else if (accumulator / 100 == 1)
    {
        //add
        address = accumulator % 100;
        accumulator = memory[address];

        accumulator += memory[address];
        programCounter ++;
    }
    else if (accumulator / 100 == 2)
    {
        //subtract
        address = accumulator % 100;
        accumulator = memory[address];

        accumulator -= memory[address];
        programCounter ++;
    }
    else if (accumulator / 100 == 3)
    {
        //store
        address = accumulator % 100;
        memory[address] = accumulator;
        programCounter ++;
    }
    else if (accumulator / 100 == 5)
    {
        //load
        address = accumulator % 100;
        accumulator = memory[address];
        programCounter ++;
    }
    else if (accumulator / 100 == 6)
    {
        //branch always
        address = accumulator % 100;
        programCounter = address;
    }
    else if (accumulator / 100 == 7)
    {
        //branch if 0
        address = accumulator % 100;
        if (address == 0)
        {
            programCounter = address;
        }
        else
        {
            programCounter++;
        }
    }
    else if (accumulator / 100 == 8)
    {
        //branch if >= 0
       address = accumulator % 100;
       if (address >= 0)
       {
           programCounter = address;
       }
       else
       {
           programCounter++;
       }
    }
    else if (accumulator / 100 == 9)
    {
        if (accumulator % 100 == 1)
        {
            //input
            cin >> accumulator;
            programCounter ++;
        }
        else if (accumulator % 100 == 2)
        {
            //output
            cout << accumulator;
            programCounter ++;
        }
    }
}
bool LittlePersonComputer::isHalted()
{
    if (memory[programCounter] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
