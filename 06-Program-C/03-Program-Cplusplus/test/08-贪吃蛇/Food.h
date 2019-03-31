//
// Created by miaopei on 2019-03-31.
//

#ifndef INC_08__FOOD_H
#define INC_08__FOOD_H

#include "Wall.h"

class Food{
public:
    Food(Wall & myWall);

    // 设置食物
    void SetFood();


    int foodX;
    int foodY;

    Wall & wall;
};

#endif //INC_08__FOOD_H
