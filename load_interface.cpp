#include "load_interface.h"

load_interface::load_interface()
{
    this->set_interface(1);
    QString buff;

    for(int i=1;i<=16;i++)
    {
        QString path("F:\\qt\\test_rpg\\test_vision1\\load_pic\\snow.png");
        QImage p ;
        buff.setNum(i);
        path.insert(41,buff);
        //qDebug()<<"debug: "<<path<<endl;
        p.load(path);
        if(p.isNull()) qDebug()<<"unload"<<endl;
        this->_pic.push_back(p);
        //delete p;
    }
    this->start = false;
    this->click.load("F:\\qt\\test_rpg\\test_vision1\\load_pic\\load_pic.png");

}

void load_interface::loadinterface(QPainter *pa)
{

    //it = this->_pic.begin();
    it++;
    if(it == this->_pic.end() || start == false)
    {
        it = this->_pic.begin();
        start = true;
    }

    if((*it).isNull())qDebug()<<"worry to load"<<endl;
    static int i = 0;
    i%=16;
    i++;
    //qDebug()<<"i: "<<i<<endl;
    //advance(it,i);//向后移动i个单位


    pa->drawImage(0,0,(*it));
     pa->drawImage(150,150,this->click);

}

void load_interface::read(QMouseEvent *m, player &p1)
{

    if(1)//按下左键
    {
        if(m->pos().x()>= 440 && m->pos().x()<= 600 && m->pos().y()>= 375 && m->pos().y()<= 409)
        {//这里是存档1的读入
            ifstream infile;
            infile.open("F:\\qt\\test_rpg\\test_vision1\\store1.txt");
            if(!infile.is_open())
            {
                exit(1);//退出程序
            }
            else
            {
                int buff;

                //这里是分别读入数据
                infile>>buff;
                p1.setDirec(buff);
                infile>>buff;
                p1.setSteps(buff);
                infile>>buff;
                p1.setState(buff);
                infile>>buff;
                p1.setX(buff);
                infile>>buff;
                p1.setY(buff);
                infile>>buff;
                p1.setLV(buff);
                infile>>buff;
                p1.setHPnow(buff);
                infile>>buff;
                p1.setHP(buff);

                infile>>buff;
                p1.setMP(buff);
                infile>>buff;
                p1.setEXP(buff);
                infile>>buff;
                p1.setEXP_now(buff);
                infile>>buff;
                p1.setAtt(buff);
                infile>>buff;
                p1.setMAtt(buff);
                infile>>buff;
                p1.setDef(buff);
                infile>>buff;
                p1.setMDef(buff);
                infile>>buff;
                p1.setCamp(buff);
                infile>>buff;
                p1.setsence(buff);
                infile>>buff;
                p1.setMAtt(buff);
                infile.close();
            }
        }

    }
}
