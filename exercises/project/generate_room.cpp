#include <iostream>

void InitializeWalls(char randomRoom[][10], int height, int width)
{
    char wall = '*';
    char empty = ' ';
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            if (column == 0 || column == width - 1)
            {
                randomRoom[row][column] = wall;
            }
            else if (row == 0 || row == height - 1)
            {
                randomRoom[row][column] = wall;
            }
            else
            {
                randomRoom[row][column] = empty;
            }
        }
    }
}

void InitializeExit(char randomRoom[][10], int height)
{
    char exit = '.';
    bool horizontal = rand() % 2;
    bool side = rand() % 2;
    int locationVertical;
    int locationHorizontal;
    side ? locationVertical = 0, locationHorizontal = 0 : locationVertical = 9, locationHorizontal = height - 1;
    horizontal ? randomRoom[locationHorizontal][rand() % 8 + 1] = exit : randomRoom[rand() % (height - 2) + 1][locationVertical] = exit;
}

void InitializePlayer(char randomRoom[][10], int height)
{
    char player = 'X';
    int row = rand() % (height - 2) + 1;
    int column = rand() % 8 + 1;

    randomRoom[row][column] = player;
}

void InitializeRoom(char randomRoom[][10], int height, int width)
{
    InitializeWalls(randomRoom, height, width);
    InitializeExit(randomRoom, height);
    InitializePlayer(randomRoom, height);
}

void ShowRoom(char randomRoom[][10], int roomHeight, int roomWidth)
{
    for (int row = 0; row < roomHeight; row++)
    {
        for (int column = 0; column < roomWidth; column++)
        {
            std::cout << randomRoom[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    int room_height = (rand() % 10) + 5;
    int room_width = 10;
    char room[room_height][10];

    InitializeRoom(room, room_height, room_width);
    ShowRoom(room, room_height, room_width);
    return 0;
}