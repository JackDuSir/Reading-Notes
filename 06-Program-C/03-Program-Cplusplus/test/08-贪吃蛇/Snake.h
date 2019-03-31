//
// Created by miaopei on 2019-03-31.
//

#ifndef INC_08__SNAKE_H
#define INC_08__SNAKE_H

#include "Wall.h"
#include "Food.h"

class Snake{
public:
    Snake(Wall & mywall, Food  & myfood);

    enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

    struct Point
    {
        int x;
        int y;
        Point *next;
    };

    // 初始化
    void InitSnake();

    // 销毁节点
    void DestroySnake();

    // 添加节点
    void AddPoint(int x,int y);

    // 删除节点
    void DeletePoint();

    // 蛇移动
    // 返回值 代表移动是否成功
    bool MoveSnake(char key);

    Point *head;
    Wall & mywall;
    Food & myfood;
    //bool isRool;    //F
};

#endif //INC_08__SNAKE_H
