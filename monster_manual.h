#ifndef MONSTER_MANUAL_H
#define MONSTER_MANUAL_H

#include"monster.h"
#include<QKeyEvent>
#include<QImage>
using namespace std;


class monster_manual
{
public:
    monster_manual();
    void turn_manual(QKeyEvent *e);
    void show_manual(QPainter *pa);

private:
    QImage mon[10];//十张怪物图鉴
    int now_pic;
};

#endif // MONSTER_MANUAL_H
