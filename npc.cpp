#include "npc.h"
#include"windows.h"

npc::npc()
{
    this->setState(0);
    this->setDirec(1);
    this->setSteps(1);
    this->setX(30);
    this->setY(20);
    this->setHP(10);
    this->setMP(5);
    this->setEXP(0);
    this->setAtt(10);
    this->setMAtt(3);
    this->setDef(1);
    this->setMDef(1);
    this->setsence(1);
    this->mission_state = 0;
}

void npc::loadmission_begin(QString s)
{
    QImage buff;
    buff.load(s);
    this->mission_begin.push_back(buff);
}

void npc::loadmission_mid(QString s)
{
    QImage buff;
    buff.load(s);
    this->mission_mid.push_back(buff);
}

void npc::loadmission_end(QString s)
{
    QImage buff;
    buff.load(s);
    this->mission_end.push_back(buff);
}

void npc::loadpicnpc(QString s)
{
    QImage buff;
    buff.load(s);
    this->all = buff.copy(QRect(0,0,32,50));
}

void npc::show(QPainter *pa)
{
    if(this->all.isNull())  qDebug()<<"npc is not load"<<endl;

    pa->drawImage(this->getX()*32,this->getY()*32,this->all);
}


void npc::showconversation(QPainter *pa)
{
    static int add = 0;
    static int gap = 0;
    vector<QImage>::iterator it;
    switch(this->mission_state)
    {
        case 0:
            it = this->mission_begin.begin();
            it += add;
            if(it == this->mission_begin.end())
            {
                add = 0;
                this->go_on_misson();
            }
            else
            {
                //if(add%4 != 0)
                pa->drawImage(0,700,(*it));
                gap++;
                if(gap % 10 == 0)
                add++;
            }


        break;

        case 1:
            for(it = this->mission_mid.begin() ; it != this->mission_mid.end(); it++)
            {

                pa->drawImage(0,700,(*it));
                //Sleep(3000);
                //system("pause");
            }
        break;

        case 2:
            for(it = this->mission_end.begin() ; it != this->mission_end.end(); it++)
            {
                pa->drawImage(0,800,(*it));
                //system("pause");
            }
        break;

        default:
            return;
    }
}

void npc::key_move(QKeyEvent *e)
{
}
