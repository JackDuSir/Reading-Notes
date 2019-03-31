//
// Created by miaopei on 2019-03-31.
//

#include "Snake.h"

Snake::Snake(Wall &mywall, Food &myfood) : mywall(mywall), myfood(myfood)
{
    this->head = NULL;
}

void Snake::InitSnake()
{
    DestroySnake();
    AddPoint(5, 4);
    AddPoint(5, 5);
    AddPoint(5, 6);
}

void Snake::DestroySnake()
{
    Point * pcur = NULL;
    while (head != NULL)
    {
        pcur = head->next;
        delete head;
        head = pcur;
    }
}

void Snake::AddPoint(int x, int y)
{
    Point * newpoit = new Point;
    newpoit->x = x;
    newpoit->y = y;
    newpoit->next = NULL;

    // 如果原来头不为空 改为身子
    if (head != NULL)
    {
        mywall.SetWall(head->x, head->y, '=');
    }

    newpoit->next = head;
    head = newpoit; // 更新头部
    mywall.SetWall(head->x, head->y, '@');
}

void Snake::DeletePoint()
{
    // 两个节点以上 才去做删除节点操作
    if (head != NULL && head->next != NULL)
    {
        Point *pre = head;
        Point *pcur = head->next;

        while (pcur->next != NULL)
        {
            pcur = pcur->next;
            pre = pre->next;
        }

        // 删除尾节点
        mywall.SetWall(pcur->x, pcur->y, ' ');
        delete pcur;
        pcur = NULL;
        pre->next = NULL;
    }
}

bool Snake::MoveSnake(char key)
{
    int x = head->x;
    int y = head->y;
    switch (key)
    {
        case UP:
            x--;
            break;
        case DOWN:
            x++;
            break;
        case LEFT:
            y--;
            break;
        case RIGHT:
            y++;
            break;
        default:
            break;
    }
    //Point *pCur = head->next;
    //Point *pPre = head;
#if 0
    while (pCur->next != NULL)
    {
        pPre = pPre->next;
        pCur = pCur->next;
    }
    if (pCur->x == x && pCur->y == y)
    {
        isRool = true;
    }
    else
    {
        if (mywall.GetWall(x, y) == '*' || mywall.GetWall(x, y) == '=')
        {
            AddPoint(x, y);
            DestroySnake();
            system("cls");
            mywall.ShowWall();
            cout << "GAME OVER!!" << endl;
            return false;
        }
    }
#endif
    // 判断用户到达位置是否成功
    if (mywall.GetWall(x, y) == '*' || mywall.GetWall(x, y) == '=')
    {
        //AddPoint(x, y);
        //DestroySnake();
        //mywall.ShowWall();
        cout << "GAME OVER!!" << endl;
        return false;
    }

    // 移动成功 分两种
    // 吃到食物 未吃到食物
    if (mywall.GetWall(x, y) == '#')
    {
        AddPoint(x, y);
        // 重新设置食物
        myfood.SetFood();
    } else {
        AddPoint(x, y);
        DeletePoint();
        #if 0
        if (isRool == true)
        {
            mywall.getseat(x, y, '@');
        }
        #endif
    }

    return true;
}
