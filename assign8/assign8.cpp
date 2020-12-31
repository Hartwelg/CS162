#include <iostream>
#include <iomanip>

using namespace std;

const int GRID = 10;
void printGrid(char array[GRID][GRID])
{
    cout << " ";
    for (int column = 0; column < GRID; column++)
    {
        cout << column;
    }
    cout << " " << endl;
    for (int row = 0; row < GRID; row++)
    {
        cout << row;
        for (int column = 0; column < GRID; column++)
        {
            cout << array[row][column];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
bool isSafe(char array[GRID][GRID],int row,int col)
{
    if (array[row][GRID] == '~' || array[GRID][col] == '~')
    {
        return false;
    }
    return true;
}
void contaminate(char array[GRID][GRID], int rowStart, int colStart)
{
    if (rowStart < 0 || colStart < 0 || rowStart >= GRID || colStart >= GRID)
    {
        return;
    }
    if (array[rowStart][colStart] != ' ')
    {
        return;
    }
    array[rowStart][colStart] = '~';

    contaminate(array, rowStart, colStart - 1);
    contaminate(array, rowStart, colStart + 1);
    contaminate(array, rowStart - 1, colStart);
    contaminate(array, rowStart + 1, colStart);

    if (array[rowStart + 1][colStart] == 'X' && array[rowStart][colStart + 1] == 'X')
    {
        contaminate(array, rowStart + 1, colStart + 1);
    }
    if (array[rowStart - 1][colStart] == 'X' && array[rowStart][colStart - 1] == 'X')
    {
        contaminate(array, rowStart - 1, colStart - 1);
    }
    if (array[rowStart + 1][colStart] == 'X' && array[rowStart][colStart - 1] == 'X')
    {
        contaminate(array, rowStart + 1, colStart - 1);
    }
    if (array[rowStart - 1][colStart] == 'X' && array[rowStart][colStart + 1] == 'X')
    {
        contaminate(array, rowStart - 1, colStart + 1);
    }
}
void copy(char thisArray[GRID][GRID], char newArray[GRID][GRID])
{
    for (int i = 0; i < GRID; i++)
    {
        for (int j = 0; j < GRID; j++)
        {
            newArray[i][j] = thisArray[i][j];
        }
    }
}
int area(char array[GRID][GRID], int row, int col, int count)
{
    if (row < 0 || col < 0 || row >= GRID || col >= GRID)
    {
        return 0;
    }
    if (array[row][col] == ' ')
    {
        return 0;
    }
    if (array[row][col] == 'X')
    {
        return 0;
    }
    if (array[row][col] == '.')
    {
        return 0;
    }
    else
    //if (array[row][col] == '~')
    {
        count++;
        array[row][col] = '.';

        if (array[row][col - 1] == '~')
        {
            return area(array, row, col - 1, count);   //left
        }
        if (array[row][col + 1] == '~')
        {
            return area(array, row, col + 1, count);   //right
        }
        if (array[row - 1][col] == '~')
        {
            return area(array, row - 1, col, count);   //up
        }
        if (array[row + 1][col] == '~')
        {
            return area(array, row + 1, col, count);   //down
        }
        if (array[row + 1][col + 1] == '~')
        {
            return area(array, row + 1, col + 1, count); //down and right
        }
        if (array[row - 1][col - 1] == '~')
        {
            return area(array, row - 1, col - 1, count); //up and left
        }
        if (array[row - 1][col + 1] == '~')
        {
            return area(array, row - 1, col + 1, count); //up and right
        }
        if (array[row + 1][col - 1] == '~')
        {
            return area(array, row + 1, col - 1, count); //down and left
        }
    return count;
    }
}
void getInput(char array[GRID][GRID])
{
    int row = 0;
    int column = 0;
    cout << "Enter wall locations (x y) and 0 0 for exit" << endl;
    while (cin >> column >> row)
    {
        if (row == 0 && column == 0)
        {
            printGrid(array);
            return;
        }
        if (array[row][column] == 'X')
        {
            cout << "Already there" << endl;
            getInput(array);
        }
        else
        {
            array[row][column] = 'X';
        }
    }
}
int main()
{
    char blocks[GRID][GRID] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',}};
    printGrid(blocks);
    getInput(blocks);
    int row = 0, col = 0;
    cout << "Enter contaminated location" << endl;
    cin >> row >> col;

    contaminate(blocks, row, col);
    printGrid(blocks);

    int count = 0;
    if (isSafe(blocks, row, col) == true)
    {
        cout << "Safe" << endl;
        char newGrid[GRID][GRID];
        copy(blocks, newGrid);
        cout << "Contaminated Area: " << area(blocks, row, col, count) << endl;
    }
    else
    {
        cout << "Not Safe" << endl;
    }
}
