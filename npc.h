#ifndef NPC_H
#define NPC_H

//npc只有属性
#include"attribute.h"
#include<QMouseEvent>
#include<QKeyEvent>
#include<QTime>
#include<QTimer>
#include<QCoreApplication>
#include"skill.h"
//npc的状态代表了对话的状态
class npc:public attribute
{
public:
    npc();
    void sleep(unsigned int msec)
    {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    void key_move(QKeyEvent *e);
    void show(QPainter *pa);//这里的show与坐标有关
    void loadpicnpc(QString s );

    void loadmission_begin(QString s);//这里的处理和图片有关
    void loadmission_mid(QString s);
    void loadmission_end(QString s);

    void setconversation(QString c);//对话以图片的形式来储存
    void showconversation(QPainter *pa);//显示对话的图片
    int getmission()const {return mission_state;}

    void go_on_misson(){this->mission_state ++;}


private:
    int mission_state;//任务完成的状态 0任务开始状态 1任务中间状态 2任务结束状态
    vector<QImage> mission_begin;
    vector<QImage> mission_mid;
    vector<QImage> mission_end;
};

#endif // NPC_H
