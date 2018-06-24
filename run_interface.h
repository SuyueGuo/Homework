#ifndef RUN_INTERFACE_H
#define RUN_INTERFACE_H
#include"interface.h"
#include"player.h"
#include<QMouseEvent>
#include<QKeyEvent>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include"map_game.h"

class run_interface:public interface
{
public:
    run_interface();
    ~run_interface(){};
    void loadinterface(QPainter *pa);//画地图的图片
    void store(QKeyEvent *m,player &p1);//储存
    void showpic(QPainter *pa);//存档成功的图片
    int getstart()const{return this->start;}

    void setstart(int i){this->start = i;}
    void return_to_head(){it_m = this->_m.begin();}

    map_game change_map(int i);//切换界面 i代表第几号地图

    void setmap(int i){this->map_num = i;}
    int getmap()const{return this->map_num;}

    vector<map_game>::iterator it_m;

private:
    int start;
    int map_num;
    QImage succeed;
    vector<map_game> _m;//把每一张地图压进去
};

#endif // RUN_INTERFACE_H
