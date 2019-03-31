#include <iostream>
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include "Wall.h"
#include "Snake.h"
#include "Food.h"

using namespace std;

int main()
{
    //添加随机种子
    srand((unsigned int)time(NULL));

    Wall wall;
    wall.InitWall();

    Food food(wall);
    food.SetFood();

    Snake snake(wall, food);
    snake.InitSnake();

    /*snake.MoveSnake('w');
    snake.MoveSnake('w');
    snake.MoveSnake('a');*/

    wall.DrowWall();

    // 接受用户的输入
    char key = getchar();

    if (snake.MoveSnake(key) == true)
    {
        // 移动成功的代码
        system("cls");
        wall.DrowWall();
        sleep(300);
    }


    return 0;
}