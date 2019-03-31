//
// Created by miaopei on 2019-03-31.
//

#ifndef INC_08__WALL_H
#define INC_08__WALL_H

#include<iostream>
using namespace std;

class Wall{
public:
    enum {
        ROW = 26,
        COL = 26
    };

    // 初始化墙壁
    void InitWall();

    // 画墙
    void DrowWall();

    // 根据索引设置 二维数组里的内容
    void SetWall(int x, int y, char c);

    // 根据索引获取当前位置的符号
    char GetWall(int x, int y);

private:
    char gameArray[ROW][COL];
};

#endif //INC_08__WALL_H
