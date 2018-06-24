#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<QPainter>
#include<vector>
#include<fstream>
#include<QString>
#include<QImage>
#include"monster.h"
#include"object.h"
#include"npc.h"
//#include<QKeyEvent>
using namespace std;
//二维数组的实现

class map_game
{
public:
    map_game();
    void show(QPainter *pa)
    {
        pa->drawImage(0,0,this->pic);
    }


    void show_mon(QPainter *pa)
    {

        for(this->it_mon = this->_mon.begin(); this->it_mon != this->_mon.end();this->it_mon++)
        {
            //qDebug()<<"--------"<<endl;
            if(this->get_map(  (*(this->it_mon)).getX(),(*(this->it_mon)).getY()  ) == 2 )
            (*(this->it_mon)).show(pa);
        }

    }

    void show_fruit(QPainter *pa)
    {
        for(this->it_fruit = this->_fruit.begin(); it_fruit!= this->_fruit.end();it_fruit++)
        {
            if(this->get_map(  (*(this->it_fruit)).getx(),(*(this->it_fruit)).gety()  ) / 10 == 4 )
            (*(this->it_fruit)).show(pa);
        }
    }

    void show_npc(QPainter *pa);

    void set_map(int x,int y,int i)
    {
        this->_map[x][y] = i;
    }
    int get_map(int x,int y)const{return this->_map[x][y];}
    void load_pic(QString path){this->pic.load(path);}

    void read_map(char *_file);

    int getnum()const{return this->num;}

    int getsx()const{return this->start_x;}
    int getsy()const{return this->start_y;}
    int getex()const{return this->end_x;}
    int getey()const{return this->end_y;}

    void setsx(int i){this->start_x = i;}
    void setsy(int i){this->start_y = i;}
    void setex(int i){this->end_x = i;}
    void setey(int i){this->end_y = i;}
    //static int num;//这是代表第几号地图

    //检测当前位置有没有怪物

    //注意： 0代表可以通过 1代表不可以通过 2代表NPC 3代表敌人 4代表物品
    //每个地图有不同的标识
    //x y代表坐标 i代表代号

    vector<npc>::iterator  it_p;
    vector<monster>::iterator it_mon;
    vector<object>::iterator it_fruit;

private:
    int num;//地图的编号
    vector<object> _fruit;
    vector<npc> buff_npc;
    vector<monster> _mon;

    QImage pic;

    int _map[61][50];

    int start_x;//起始点坐标(后一张图片进入上一张图片的坐标)
    int start_y;

    int end_x;//按顺序--房子进入村庄的顺序
    int end_y;



};

#endif // MAP_H
