#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include<QImage>
#include<string>
#include<map>
#include<QPainter>
#include<QString>
#include<QDebug>
#include"position.h"
using namespace std;
class object:public position
{
public:
    static map<string,object> GAME_OBJECT_SET;
        //确定各类物体子素材图片的位置，高、宽等数据
    static object find(string type);

    void show(QPainter *pa)
    {
        if(fruit_buff.isNull()) qDebug()<<"wrong to load"<<endl;
        pa->drawImage(this->posx*32,this->posy*32,fruit_buff);
    }


    void loadpic(QString name)
    {
        this->fruit_buff.load(name);
    }

        //根据物体类型名找到图标
    object(){}
    object(string type);

    int get_fruit_hp()const{return this->fruit_HP;}
    void set_fruit_hp(int i){this->fruit_HP = i;}

private:
    QImage fruit_buff;
    string _type;
    int fruit_HP;
};

#endif // OBJECT_H
