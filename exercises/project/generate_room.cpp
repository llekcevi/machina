#include <iostream>

int main()
{   
    srand(time(NULL));
    int rowN = (rand()%10)+5;       //10
    int columnN= (rand()%10)+5;     //10
    char room[rowN][columnN];       //[10][10]
    char wall = '#';
    char player = 'X';
    
    //initialize room
    for (int row = 0; row < rowN; row++)
    {
        for (int column = 0; column < columnN; column++)
        {
            if (column == 0 || column == columnN-1)
            {
                room[row][column] = wall;
            }
            else if (row == 0 || row == rowN-1)
            {
                room[row][column] = wall;
            }
            else
            {
                room[row][column] = ' ';
            }
        }
    }
    
    //show room
    for (int row = 0; row < rowN; row++)
    {
        for (int column = 0; column < columnN; column++)
        {
            std::cout << room[row][column] << " ";
        }
        std::cout << std::endl;
    }
    //
    return 0;
}