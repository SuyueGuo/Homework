#include "monster_manual.h"

monster_manual::monster_manual()
{
    this->now_pic = -1;

    this->mon[0].load(":/monster/mon1.png");
    this->mon[1].load(":/monster/mon2.png");
    this->mon[2].load(":/monster/mon3.png");
    this->mon[3].load(":/monster/mon4.png");
    this->mon[4].load(":/monster/mon5.png");
    this->mon[5].load(":/monster/mon6.png");
    this->mon[6].load(":/monster/mon7.png");
    this->mon[7].load(":/monster/mon8.png");
    this->mon[8].load(":/monster/mon9.png");
    this->mon[9].load(":/monster/mon10.png");
}

void monster_manual::turn_manual(QKeyEvent *e)
{
    if(e->key() == Qt::Key_N)
    {
        this->now_pic++;
        //qDebug()<<"------------"<<this->now_pic<<endl;
        if(this->now_pic == 11)
        {
            now_pic = -1;
        }
    }
    else if(e->key() == Qt::Key_F1)
    {
         now_pic = -1;
    }
}

void monster_manual::show_manual(QPainter *pa)
{
    if(this->now_pic >= 0)
    {
        if(mon[this->now_pic].isNull()) qDebug()<<"wrong to load manual"<<endl;
        pa->drawImage(200,200,mon[this->now_pic]);
    }
}
