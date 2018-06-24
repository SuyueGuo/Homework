#ifndef PLAYER_H
#define PLAYER_H

#include"attribute.h"
#include"skill.h"
#include"weapon.h"
#include<QMouseEvent>
#include<QKeyEvent>
#include<QFont>
//玩家--属性与技能构成了玩家
class player:public attribute
{
public:
    player();
    void attack(QKeyEvent *k);//按键来发出攻击
    void key_move(QKeyEvent *e);
    void show(QPainter *pa);
    void show_blood(QPainter *pa);

    void setmoney(long i){this->money = i;}
    long getmoney()const{return this->money;}

    void setskillnum(int i){this->skill_num = i;}
    int getskillnum()const{return this->skill_num;}
    //skill &getskill(){return this->sl[skill_num];}
    skill sl[4];//用数组来实现
    static int GRID_SIZE;
    //vector<skill>::iterator it_skill;//迭代器

private:
    int skill_num;
    long money;

    //vector<skill> sl;//技能在构造函数里实现

};

#endif // PLAYER_H
