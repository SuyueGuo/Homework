#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>
#include<QDebug>
#include<QImage>
#include<QMouseEvent>
#include<QPainter>
#include"object.h"
using namespace std;


class weapon
{
public:
    weapon(){this->_type = 100;}
    ~weapon(){}
    //设置属性
    void setHp(int h){_hp = h;}
    void setMp(int m){_mp = m;}
    void setAtt(int a){_attack = a;}
    void setDef(int d){_defend = d;}
    void setMAtt(int ma){_m_attack = ma;}
    void setMDef(int md){_m_defend = md;}
    void intial(string type);

    bool state(){return _state;}
    int getHp()const{return this->_hp;}
    int getMp()const{return this->_mp;}
    int getatt()const{return this->_attack;}
    int getmatt()const{return this->_m_attack;}
    int getdef()const{return this->_defend;}
    int getmdef()const{return this->_m_defend;}
    int getType(){return this->_type;}
    QImage pic(){return _pic;}
    string typeName(){return this->_type_name;}
private:
    object _info;
    QImage _pic;
    bool _state;
    string _type_name;
    int _type;
    int _hp;
    int _mp;
    int _attack;
    int _m_attack;
    int _defend;
    int _m_defend;
};

#endif // WEAPON_H
