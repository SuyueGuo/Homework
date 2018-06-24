#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include<QImage>
#include<iostream>
#include<vector>
#include<QKeyEvent>
#include<QDebug>
#include<QRect>
#include<ctime>
#include<QPainter>
#include"position.h"
//这里是人物的属性
using namespace std;

class attribute
{
public:
    attribute();
    //这里是修改属性的函数：
    void setX(int x){_posX = x;}
    void setY(int y){_posY = y;}
    void setDirec(int d){_direc = d;}
    void setSteps(int s){_steps = s;}
    void setHP(int h){_HP = h; _HPnow = h;}
    void setMP(int m){_MP = m; _MPnow = m;}
    void setEXP(int e){_EXP = e;}
    void setEXP_now(int e){this->_EXPnow = e;}
    void setLV(int l){_LV = l;}
    void setAtt(int a){_attack = a;}
    void setDef(int d){_defend = d;}
    void setMAtt(int ma){_m_attack = ma;}
    void setMDef(int md){_m_defend = md;}
    void setCamp(int c){_camp = c;}
    void setState(int s){_state = s;}
    void setsence(int c){ this->_sence = c;}
    void setHPnow(int e){this->_HPnow = e;}

    //这些函数是返回属性值
    int getX()const {return _posX;}
    int getY()const {return _posY;}
    int getallHP()const{return this->_HP;}
    short getDirec()const{return _direc;}
    int getSteps()const{return _steps;}
    int getHP()const{return _HPnow;}
    int getMP()const{return this->_MP;}
    int getLV()const{return this->_LV;}
    int getsence()const{return this->_sence;}
    int getcamp()const{return this->_camp;}
    int getstate()const{return this->_state;}
    int getatt()const{return (this->_real[2] >this->_attack ? this->_real[2] :this->_attack );}
    int getmatt()const{return this->_m_attack;}
    int getdef()const{ return (this->_real[4]> this->_defend ?  this->_real[4] : this->_defend);}
    int getmdef()const{return this->_m_defend;}
    int getexp()const{return this->_EXP;}
    int getexpnow()const{return this->_EXPnow;}
    QImage getpic() const{return this->all;}

    //这些函数是与属性值相关的函数
    void move(int direction, int steps);//人物的移动
    void loadAll(QString path);//加载图片
    //void loadNow();
    void LVup();
    void injured(int n_attack);
    void healed(int HP);
    void addEXP(int e);
    void death();
    void strengthen(int str[]);

    virtual void key_move(QKeyEvent *e){};
    virtual void show(QPainter *pa){};

protected:

    QImage all;
    //QImage now;
    vector<QImage> pic;
    vector<QImage>::iterator it_pic;

    vector<QImage> fight;//战斗模式技能的图片

    QImage fight_all;//总的战斗图片

    short _direc;//0123 下左右上
    int _steps;//人物走的步数
    int _state;    //0死亡1正常
    int _posX;  //人物的坐标
    int _posY;
    int _LV;      //等级
    int _HP;      //生命值
    int _HPnow;     //当前生命
    int _MP;      //魔法值
    int _MPnow;     //当前魔法
    int _EXP;     //经验值
    int _EXPnow;   //当前经验
    int _attack;        //攻击力
    int _m_attack;  //魔法攻击
    int _defend;        //防御力
    int _m_defend; //魔法防御
    int _camp;     //阵营
    int _sence; //场景 1.游走模式 2.战斗模式 3.放技能的图片（另外加的）
    int _real[6];
};

#endif // ATTRIBUTE_H
