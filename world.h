#ifndef WORLD_H
#define WORLD_H
#include <QMainWindow>
#include<QPaintEvent>
#include<QKeyEvent>
#include<QDebug>
#include<QTime>
#include<QTimer>

#include"interface.h"
#include"load_interface.h"
#include"run_interface.h"
#include"player.h"
#include"attribute.h"
#include"monster.h"
#include"npc.h"
#include"fight_interface.h"
#include"monster_manual.h"
#include"bag_system.h"
#include"money_system.h"
using namespace std;



class world
{
public:
    world();

    void show(QPainter *pa);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void setinterface(short i){this->now_interface = i;}
    short getinterface()const{return this->now_interface;}

    void setmonsternum(int i){this->monster_num = i;}
    int getmonsternum()const{return this->monster_num;}

private:
    load_interface *ld;
    run_interface *rd;
    player *_player1;
    monster_manual m1;
    monster *_monster1;
    fight_interface *fd;
    npc npc1[10];//最大有十个NPC
    monster _mon[10];
    object fruit[6];
    //monster monster1;
    //QTimer *monster_move;
    int monster_num;//怪物的顺序
    int npc_num;
    int fruit_num;
    short now_interface;//现在的界面 1.登录界面 2.游走界面 3.战斗界面
    bag_system _bag;
    int _n_select;//被选中的物品
    int _strengthen[6];
    money_system _money_sys;
};

#endif // WORLD_H
