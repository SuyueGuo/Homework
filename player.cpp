#include "player.h"
#include"windows.h"

int player::GRID_SIZE = 32;

player::player()
{
    //第一个技能--普通攻击
    //技能的实现
    //first.set_CD(10);
    //first.set_state(1);
    this->_state = 1;
    this->sl[0].set_harm(2);
    this->sl[0].set_type(1);
    this->sl[0].store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\file.png");

    this->sl[1].set_harm(3);
    this->sl[1].set_type(1);
    this->sl[1].store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\skill2.png");

    this->sl[2].set_harm(8);
    this->sl[2].set_type(1);
    this->sl[2].store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\skill3.png");

    this->sl[3].set_harm(11);
    this->sl[3].set_type(1);
    this->sl[3].store_pic("F:\\qt\\test_rpg\\test_vision1\\pic\\file.png");


    this->setskillnum(0);


    //设置人物属性
    this->setDirec(1);
    this->setSteps(1);
    this->setState(1);
    this->setX(20);
    this->setY(20);
    this->setLV(1);
    this->setHP(40);
    this->setMP(5);
    this->setEXP_now(0);
    this->setEXP(10);
    this->setAtt(10);
    this->setMAtt(1);
    this->setDef(9);
    this->setMDef(1);
    this->setCamp(0);
    this->setsence(1);
    _real[0] = _HP;
    _real[1] = _MP;
    _real[2] = _attack;
    _real[3] = _m_attack;
    _real[4] = _defend;
    _real[5] = _m_defend;

    //设置图片
    this->loadAll("F:\\qt\\test_rpg\\test_vision1\\pic\\player.png");
    this->fight_all.load(":/player/player1_1.png");

    QImage buff;
    //buff.load("F:\\qt\\test_rpg\\test_vision1\\pic\\attack.png");
    QImage attack_pic;

   // this->fight_all.load("F:\\qt\\test_rpg\\test_vision1\\pic\\fight_player.png");//加载总的战斗图片
    buff.load(":/player/player1_1.png");
    if(buff.isNull()) qDebug()<<"wrong to load fight"<<endl;
    this->fight.push_back(buff);
    buff.load(":/player/player1_2.png");
    this->fight.push_back(buff);
    buff.load(":/player/player1_3.png");
    this->fight.push_back(buff);
    buff.load(":/player/player1_4.png");
    this->fight.push_back(buff);//加载释放技能的图片


    if(this->all.isNull()) qDebug()<<"all is wrong"<<endl;
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            QImage now = this->all.copy(QRect(j*GRID_SIZE,i*50,1*32,1*50));
            if(now.isNull()) qDebug()<<"now is null "<<endl;
            this->pic.push_back(now);
        }
    }
}

void player::key_move(QKeyEvent *e)
{
    if(e->key() == Qt::Key_A)
    {
        this->move(2,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->move(3,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->move(4,1);
    }
    else if(e->key() == Qt::Key_S)
    {
        this->move(1,1);
    }

}

void player::show(QPainter *pa)
{
    static int time = 0;
    if(this->_sence ==1)//游走模式
    {
        this->it_pic = this->pic.begin();
        this->it_pic += (this->_direc-1)*4 + this->_steps;
        if((*it_pic).isNull()) qDebug()<<"wrong to load this player"<<endl;
        pa->drawImage(this->_posX*32,this->_posY*32,(*it_pic));
    }
    else if(this->_sence == 2 )//战斗模式
    {
        time = 0;
        int buffx = this->getX();
        int buffy = this->getY();
        this->setX(3);
        this->setY(9);
        this->show_blood(pa);
        pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,this->fight_all);
        this->setX(buffx);
        this->setY(buffy);
    }
    else if(this->_sence == 3)
    {
        /*for(this->it_pic = this->fight.begin();it_pic != this->fight.end();it_pic++)
        {
            pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,*(this->it_pic));
            //Sleep(800);
        }*/
        //static int time = 0;
        int buffx = this->getX();
        int buffy = this->getY();
        this->setX(3);
        this->setY(9);
        this->show_blood(pa);
        this->it_pic = this->fight.begin();
        this->it_pic += time;
        qDebug()<<"time:"<<time<<endl;
        if(it_pic == this->fight.end() )
        {
            time = 0;
            this->setsence(4);//放完图片切回2
        }
        else
        {
            pa->drawImage(this->_posX*GRID_SIZE,this->_posY*GRID_SIZE,*(this->it_pic));
            time++;
        }
        this->setX(buffx);
        this->setY(buffy);

    }


    QRect word(0,0,100,50);
    pa->setPen(Qt::white);
    QString lv_show;
    lv_show.setNum(this->getLV());
    lv_show.insert(0,"人物等级:");
    QFont font ( "Microsoft YaHei", 10, 75);
    pa->setFont(font);
    pa->drawText(word,lv_show);

    QRect word1(0,55,100,50);
    pa->setPen(Qt::white);
    QString attack1;
    attack1.setNum(this->getatt());
    attack1.insert(0,"攻击力:");
    pa->drawText(word1,attack1);

    QRect word2(0,110,100,50);
    pa->setPen(Qt::white);
    QString defend1;
    defend1.setNum(this->getdef());
    defend1.insert(0,"防御力：");
    pa->drawText(word2,defend1);

    QRect word3(0,165,100,50);
    pa->setPen(Qt::white);
    QString life;
    life.setNum(this->getHP());
    life.insert(0,"生命值：");
    pa->drawText(word3,life);
}

void player::show_blood(QPainter *pa)
{
    pa->setBrush(Qt::NoBrush);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.6) * GRID_SIZE, GRID_SIZE, GRID_SIZE / 8);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.4) * GRID_SIZE, GRID_SIZE, GRID_SIZE / 8);

    pa->setBrush(Qt::red);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.6) * GRID_SIZE, _HPnow * GRID_SIZE / _HP, GRID_SIZE / 8);
    pa->setBrush(Qt::blue);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.4) * GRID_SIZE, _MPnow * GRID_SIZE / _MP, GRID_SIZE / 8);
    pa->setBrush(Qt::yellow);
    pa->drawRect(this->_posX * GRID_SIZE, (this->_posY - 0.8) * GRID_SIZE, this->_EXPnow * GRID_SIZE / this->_EXP, GRID_SIZE / 8);


}

void player::attack(QKeyEvent *k)
{
    if(k->key() == Qt::Key_G)
    {
        if(this->getLV() >= 1)
        {
             this->setsence(3);
             this->skill_num = 0;
        }
    }
    else if(k->key() == Qt::Key_H)
    {
        if(this->getLV() >= 3)
        {
             this->setsence(3);
             this->skill_num = 1;
        }
    }
    else if(k->key() == Qt::Key_J)
    {
        if(this->getLV() >= 5)
        {
             this->setsence(3);
             this->skill_num = 2;
        }
    }
    else if(k->key() == Qt::Key_K)
    {
        if(this->getLV() >= 10)
        {
             this->setsence(3);
             this->skill_num = 3;
        }

    }
}
