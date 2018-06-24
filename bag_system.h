#ifndef BAG_SYSTEM_H
#define BAG_SYSTEM_H

#include"system.h"
//背包系统
#include"weapon.h"
#include<QImage>
#include<QString>
#include<QPainter>
#include<QDebug>
#include<ctime>
class bag_system:public system
{
public:
    bag_system();
    void initial();
    void open();
    void show(QPainter *pa);
    void equip(int num, int strengthen[]);
    bool opend(){return _state;}
    void getWeaponRandom();
    string getType(int num);
    void remove(int num);
private:
    bool _state;
    weapon equipped[6];
    //0头盔1铠甲2靴子3护手4武器5防具
    QImage a_bag;
    QImage a_equipped;
    int _num;//容纳量
    int _n_picked;
    weapon picked[24];
};

#endif // BAG_SYSTEM_H
