//
// Created by miaopei on 2019-03-31.
//

#include "Food.h"

Food::Food(Wall &myWall) : wall(myWall)
{

}

void Food::SetFood()
{
    while (true)
    {
        foodX = rand() % (Wall::ROW - 2) + 1;
        foodY = rand() % (Wall::COL - 2) + 1;

        // 如果随机的时蛇头或者是蛇身 应该重新再生成
        if (wall.GetWall(foodX, foodY) == ' ')
        {
            wall.SetWall(foodX, foodY, '#');
            break;
        }
    }
}
