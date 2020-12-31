#ifndef LITTLEPERSONCOMPUTER_H
#define LITTLEPERSONCOMPUTER_H

#include <iostream>
#include <cmath>
#include <iomanip>

#endif // LITTLEPERSONCOMPUTER_H

/**
 * @brief The LittlePersonComputer class contains all of the functions that the lpc can do
 */
class LittlePersonComputer{
public:
/**
 * @brief LittlePersonComputer implements the lpc class
 */
LittlePersonComputer();
/**
 * @brief LittlePersonComputer::LittlePersonComputer creates the lpc
 * @param instructions - instructions to be given to the lpc
 * @param numberOfInstructions - number of instructions given to the lpc
 */
LittlePersonComputer(int instructions[], int numberOfInstructions);
/**
 * @brief restart restarts the lpc > acc, pc to 0
 */
restart();
/**
 * @brief reset resets the lpc > acc, pc, mem. to 0
 */
reset();
/**
 * @brief loadProgram loads a program into the lpc
 * @param instructions instructions to be given to lpc
 * @param numberOfInstructions number of instructions for the lpc
 */
loadProgram(int instructions[], int numberOfInstructions);
/**
 * @brief printState prints the state of the computer
 */
printState();
/**
 * @brief getCurrentInstruction gets the current instruction of the lpc
 * @return current instruction
 */
int getCurrentInstruction();
/**
 * @brief step steps the computer to the next instruction
 */
step();
/**
 * @brief isHalted checks whether the lpc is halted
 * @return whether lpc is halted or not
 */
bool isHalted();
private:
int memory [20] = {}; // memory of the lpc, stores all instructions and data
int accumulator;    //stores the current instruction or data
int programCounter; //keeps track of step in program
};
