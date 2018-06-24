#ifndef MONSTER_H
#define MONSTER_H
#include"attribute.h"
#include"skill.h"
#include<QMouseEvent>
#include<QKeyEvent>

class monster:public attribute
{
public:
    monster();
    void attack();//自动攻击
    void return_head(){it_skill = this->sl.begin();}
    void key_move(QKeyEvent *e){};//自己移动暂时不用处理
    void show(QPainter *pa);

    void loadfightall(QString p){this->fight_all.load(p);}
    void loadfight(QString p);

    void setexp(int i){mon_exp = i;}
    int getmonexp() const{return this->mon_exp;}

    /*monster( monster &m1)
    {
        m1.return_head();
        this->sl.push_back( (*m1.it_skill) );
    }*/

    static int GRID_SIZE;
    //自己移动的一个槽函数
    void move_monster();
    vector<skill>::iterator it_skill;//迭代器

private:
    vector<skill> sl;//技能在构造函数里实现
    int mon_exp;

};

#endif // MONSTER_H
