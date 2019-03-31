//
// Created by miaopei on 2019-03-31.
//

#include "Wall.h"

void Wall::InitWall()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // 放墙壁
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1){
                gameArray[i][j] = '*';
            } else {
                gameArray[i][j] = ' ';
            }
        }
    }
}

void Wall::DrowWall()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << gameArray[i][j] << " ";
        }
        if (i == 5)
        {
            cout << "   create by Mr.Miaow";
        }
        if (i == 6)
        {
            cout << "   a : left";
        }
        if (i == 7)
        {
            cout << "   d : right";
        }
        if (i == 8)
        {
            cout << "   w : up";
        }
        if (i == 9)
        {
            cout << "   s : down";
        }
        cout << endl;
    }
}

void Wall::SetWall(int x, int y, char c)
{
    gameArray[x][y] = c;
}

char Wall::GetWall(int x, int y)
{
    return gameArray[x][y];
}
