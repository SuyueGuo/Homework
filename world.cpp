#include "world.h"
#include<windows.h>
world::world()
{

    this->now_interface = 1;
    this->ld = new load_interface;
    this->rd = new run_interface;
    this->fd = new fight_interface;
    this->_player1 = new player;
    this->_monster1 = new monster;
    //this->npc1 = new NPC;
    //const monster &monster1 = ( (*(rd->it_m)).exam_mon(this->_player1->getX(),this->_player1->getY()) );

    this->npc1[1].loadpicnpc(":/pic/npc1.png");
    this->npc1[1].loadmission_begin(":/conversation/npc1_1.png");
    this->npc1[1].loadmission_begin(":/conversation/npc1_2.png");
    this->npc1[1].loadmission_begin(":/conversation/npc1_3.png");

    this->npc1[2].loadpicnpc(":/pic/npc2.png");
    this->npc1[2].loadmission_begin(":/conversation/npc2_1.png");
    this->npc1[2].loadmission_begin(":/conversation/npc2_2.png");
    this->npc1[2].loadmission_begin(":/conversation/npc2_3.png");

    this->npc1[3].loadpicnpc(":/pic/npc1.png");
    this->npc1[3].loadmission_begin(":/conversation/npc3_1.png");
    this->npc1[3].loadmission_begin(":/conversation/npc3_2.png");

    this->npc_num = 0;
    this->monster_num = 0;
    this->fruit_num  = 0;

    this->fruit[0].set_fruit_hp(2);
    this->fruit[1].set_fruit_hp(5);
    this->fruit[2].set_fruit_hp(8);
    this->fruit[3].set_fruit_hp(10);
    this->fruit[4].set_fruit_hp(15);
    this->fruit[5].set_fruit_hp(25);


    //第一只怪物的属性
    this->_mon[0].setDirec(1);
    this->_mon[0].setSteps(1);
    this->_mon[0].setState(1);
    this->_mon[0].setX(30);
    this->_mon[0].setY(20);
    this->_mon[0].setHP(15);
    this->_mon[0].setMP(5);
    this->_mon[0].setEXP(0);
    this->_mon[0].setAtt(2);
    this->_mon[0].setMAtt(3);
    this->_mon[0].setDef(1);
    this->_mon[0].setMDef(1);
    this->_mon[0].setsence(1);
    this->_mon[0].setexp(2);

    this->_mon[0].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster1_all.png");
    this->_mon[0].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster11.png");
    this->_mon[0].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster12.png");
    this->_mon[0].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster13.png");
    this->_mon[0].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster14.png");

    this->_mon[1].setDirec(1);
    this->_mon[1].setSteps(1);
    this->_mon[1].setState(1);
    this->_mon[1].setX(30);
    this->_mon[1].setY(20);
    this->_mon[1].setHP(20);
    this->_mon[1].setMP(5);
    this->_mon[1].setEXP(0);
    this->_mon[1].setAtt(4);
    this->_mon[1].setMAtt(3);
    this->_mon[1].setDef(3);
    this->_mon[1].setMDef(1);
    this->_mon[1].setsence(1);
    this->_mon[1].setexp(3);


    this->_mon[1].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster2_all.png");
    this->_mon[1].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster21.png");
    this->_mon[1].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster22.png");
    this->_mon[1].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster23.png");
    this->_mon[1].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster24.png");


    this->_mon[2].setDirec(1);
    this->_mon[2].setSteps(1);
    this->_mon[2].setState(1);
    this->_mon[2].setX(30);
    this->_mon[2].setY(20);
    this->_mon[2].setHP(30);
    this->_mon[2].setMP(5);
    this->_mon[2].setEXP(0);
    this->_mon[2].setAtt(8);
    this->_mon[2].setMAtt(3);
    this->_mon[2].setDef(6);
    this->_mon[2].setMDef(1);
    this->_mon[2].setsence(1);
    this->_mon[2].setexp(8);

    this->_mon[2].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster3_all.png");
    this->_mon[2].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster31.png");
    this->_mon[2].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster32.png");
    this->_mon[2].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster33.png");
    this->_mon[2].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster34.png");

    this->_mon[3].setDirec(1);
    this->_mon[3].setSteps(1);
    this->_mon[3].setState(1);
    this->_mon[3].setX(30);
    this->_mon[3].setY(20);
    this->_mon[3].setHP(45);
    this->_mon[3].setMP(5);
    this->_mon[3].setEXP(0);
    this->_mon[3].setAtt(10);
    this->_mon[3].setMAtt(3);
    this->_mon[3].setDef(10);
    this->_mon[3].setMDef(1);
    this->_mon[3].setsence(1);
    this->_mon[3].setexp(12);

    this->_mon[3].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster4_all.png");
    this->_mon[3].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster4_all.png");
    this->_mon[3].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster4_all.png");
    this->_mon[3].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster4_all.png");
    this->_mon[3].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster4_all.png");


    this->_mon[4].setDirec(1);
    this->_mon[4].setSteps(1);
    this->_mon[4].setState(1);
    this->_mon[4].setX(30);
    this->_mon[4].setY(20);
    this->_mon[4].setHP(45);
    this->_mon[4].setMP(5);
    this->_mon[4].setEXP(0);
    this->_mon[4].setAtt(10);
    this->_mon[4].setMAtt(3);
    this->_mon[4].setDef(18);
    this->_mon[4].setMDef(1);
    this->_mon[4].setsence(1);
    this->_mon[4].setexp(18);

    this->_mon[4].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster5_all.png");
    this->_mon[4].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster5_all.png");
    this->_mon[4].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster5_all.png");
    this->_mon[4].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster5_all.png");
    this->_mon[4].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster5_all.png");


    this->_mon[5].setDirec(1);
    this->_mon[5].setSteps(1);
    this->_mon[5].setState(1);
    this->_mon[5].setX(30);
    this->_mon[5].setY(20);
    this->_mon[5].setHP(50);
    this->_mon[5].setMP(5);
    this->_mon[5].setEXP(0);
    this->_mon[5].setAtt(20);
    this->_mon[5].setMAtt(3);
    this->_mon[5].setDef(14);
    this->_mon[5].setMDef(7);
    this->_mon[5].setsence(1);
    this->_mon[5].setexp(20);

    this->_mon[5].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster6_all.png");
    this->_mon[5].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster6_all.png");
    this->_mon[5].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster6_all.png");
    this->_mon[5].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster6_all.png");
    this->_mon[5].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster6_all.png");

    this->_mon[6].setDirec(1);
    this->_mon[6].setSteps(1);
    this->_mon[6].setState(1);
    this->_mon[6].setX(30);
    this->_mon[6].setY(20);
    this->_mon[6].setHP(60);
    this->_mon[6].setMP(5);
    this->_mon[6].setEXP(0);
    this->_mon[6].setAtt(25);
    this->_mon[6].setMAtt(3);
    this->_mon[6].setDef(18);
    this->_mon[6].setMDef(1);
    this->_mon[6].setsence(1);
    this->_mon[6].setexp(24);

    this->_mon[6].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster7_all.png");
    this->_mon[6].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster7_all.png");
    this->_mon[6].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster7_all.png");
    this->_mon[6].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster7_all.png");
    this->_mon[6].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster7_all.png");

    this->_mon[7].setDirec(1);
    this->_mon[7].setSteps(1);
    this->_mon[7].setState(1);
    this->_mon[7].setX(30);
    this->_mon[7].setY(20);
    this->_mon[7].setHP(85);
    this->_mon[7].setMP(5);
    this->_mon[7].setEXP(0);
    this->_mon[7].setAtt(28);
    this->_mon[7].setMAtt(3);
    this->_mon[7].setDef(20);
    this->_mon[7].setMDef(1);
    this->_mon[7].setsence(1);
    this->_mon[7].setexp(26);

    this->_mon[7].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster8_all.png");
    this->_mon[7].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster8_all.png");
    this->_mon[7].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster8_all.png");
    this->_mon[7].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster8_all.png");
    this->_mon[7].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster8_all.png");

    this->_mon[8].setDirec(1);
    this->_mon[8].setSteps(1);
    this->_mon[8].setState(1);
    this->_mon[8].setX(30);
    this->_mon[8].setY(20);
    this->_mon[8].setHP(120);
    this->_mon[8].setMP(5);
    this->_mon[8].setEXP(0);
    this->_mon[8].setAtt(40);
    this->_mon[8].setMAtt(3);
    this->_mon[8].setDef(30);
    this->_mon[8].setMDef(1);
    this->_mon[8].setsence(1);
    this->_mon[8].setexp(26);
    this->_mon[8].setexp(30);

    this->_mon[8].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster9_all.png");
    this->_mon[8].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster9_all.png");
    this->_mon[8].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster9_all.png");
    this->_mon[8].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster9_all.png");
    this->_mon[8].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster9_all.png");

    this->_mon[9].setDirec(1);
    this->_mon[9].setSteps(1);
    this->_mon[9].setState(1);
    this->_mon[9].setX(30);
    this->_mon[9].setY(20);
    this->_mon[9].setHP(1000);
    this->_mon[9].setMP(5);
    this->_mon[9].setEXP(0);
    this->_mon[9].setAtt(100);
    this->_mon[9].setMAtt(3);
    this->_mon[9].setDef(100);
    this->_mon[9].setMDef(1);
    this->_mon[9].setsence(1);
    this->_mon[9].setexp(100);

    this->_mon[9].loadfightall("F:\\qt\\test_rpg\\test_vision1\\pic\\monster10_all.png");
    this->_mon[9].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster10_all.png");
    this->_mon[9].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster10_all.png");
    this->_mon[9].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster10_all.png");
    this->_mon[9].loadfight("F:\\qt\\test_rpg\\test_vision1\\pic\\monster10_all.png");

    this->_bag.initial();
    _n_select = 0;
    for(int i = 0; i < 6; i++){
        _strengthen[i] = 0;
    }
}

void world::show(QPainter *pa)
{
    //const monster &monster1 = ( (*(rd->it_m)).exam_mon(this->_player1->getX(),this->_player1->getY()) );
    //this->_player1->setsence(3);
    //this->change_interface(1,1);
    //if(this->now_interface == 1);
    Sleep(100);
    switch(this->now_interface)
    {//画出界面
        case 1:
        //qDebug()<<"1"<<endl;
            this->ld->loadinterface(pa);
            break;

        case 2:

            //const monster &monster1 = ( (*(rd->it_m)).exam_mon(this->_player1->getX(),this->_player1->getY()) );
            this->rd->return_to_head();
            this->rd->it_m += this->rd->getmap();
            this->rd->loadinterface(pa);



            if(this->rd->getmap() == 18)
            {
                QImage boss;
                boss.load(":/monster/boss.png");
                pa->drawImage(16*32,7*32,boss);
            }




            //qDebug()<<"    "<<this->rd->getmap()<<endl;
            if((*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() )== 5)
            {
                this->rd->setmap( this->rd->getmap() + 1);
                this->rd->it_m += 1 ;
                this->_player1->setX((*(rd->it_m)).getex() );
                this->_player1->setY((*(rd->it_m)).getey() );

            }
            else if((*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() )== 6)
            {
                this->rd->setmap( this->rd->getmap() - 1);
                this->rd->it_m -= 1 ;
                this->_player1->setX((*(rd->it_m)).getsx() );
                this->_player1->setY((*(rd->it_m)).getsy() );

            }
            else if( ( (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) ) / 10 == 2)
            {
                //const monster &monster1 = ( (*(rd->it_m)).exam_mon(this->_player1->getX(),this->_player1->getY()) );
                //this->_player1->setsence(3);
                this->monster_num = ( (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) ) % 20;
                qDebug()<<"mon_num"<<this->monster_num<<endl;
                this->now_interface = 3;
                this->_player1->setsence(2);
                this->_mon[this->monster_num].setsence(2);
                (*(rd->it_m)).set_map(this->_player1->getX(),this->_player1->getY(),0);
                //(*this->_player1->it_skill).it_pic = (*this->it_skill).pic.begin();
            }//交换指针
            else if( (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) / 10== 3)
            {
                this->npc_num = (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) % 30;
                this->npc1[this->npc_num].showconversation(pa);
            }
            else if( (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) / 10 == 4)
            {
                this->fruit_num = (*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) % 40;
                _player1->healed( this->fruit[this->fruit_num].get_fruit_hp() );
                (*(rd->it_m)).set_map(this->_player1->getX(),this->_player1->getY(),0);

            }

            /*if(this->rd->getstart() == 1)
            {
                this->rd->showpic(pa);
                Sleep(1000);
            }*/
            this->_player1->show(pa);
            //this->_monster1[this->monster_num].show(pa);
            (*(rd->it_m)).show_npc(pa);
             m1.show_manual(pa);
             (*(rd->it_m)).show_fruit(pa);
            //this->_monster1->show(pa);
            //this->_monster1->show(pa);

            break;

        case 3:
        this->rd->return_to_head();
        this->rd->it_m += this->rd->getmap();

        this->fd->loadinterface(pa);
        //int _sx = this->_player1->getX();
        //int _sy = this->_player1->getY();
        switch(this->fd->get_turn())
        {
            case 1:
                if(this->_player1->getsence() == 4)
                {
                    this->fd->changeturn();
                    this->_mon[this->monster_num].attack();
                    this->_player1->setsence(2);

                }
                else if(this->_player1->getsence() == 3)
                {

                    (this->_player1->sl[this->_player1->getskillnum()]).show(pa,(this->_mon[this->monster_num].getX()-1)*32,(this->_mon[this->monster_num].getY()-0.4)*32);
                    this->_mon[this->monster_num].injured ( (this->_player1->sl[this->_player1->getskillnum()] ).get_harm() +this->_player1->getatt());
                    this->_mon[this->monster_num].death();
                    if(this->_mon[this->monster_num].getstate() == 0)
                    {


                        this->now_interface = 2;
                        if(this->getmonsternum() == 9)
                        {
                           this->now_interface = 4;
                        }




                        //const_cast<monster &>(monster1).setState(1);
                        //(*(rd->it_m)).
                        /*if(this->monster1.getstate() == 0)
                        {
                            (*(rd->it_m)).set_map(this->monster1.getX(),this->monster1.getY(),0);//清零
                        }*/
                        this->_mon[this->monster_num].setsence(1);
                        this->_mon[this->monster_num].setState(1);//死亡判断
                        this->_mon[this->monster_num].setHPnow(this->_mon[this->monster_num].getallHP());
                        this->_player1->addEXP(this->_mon[this->monster_num].getmonexp());
                        this->_player1->setsence(1);
                        this->_bag.getWeaponRandom();
                    }
                    Sleep(100);
                    //this->_player1->setsence(2);
                }

            case 2:
                if(this->_mon[this->monster_num].getsence() == 3)
                {
                    int buffx = this->_player1->getX();
                    int buffy = this->_player1->getY();
                    this->_player1->setX(3);
                    this->_player1->setY(7);
                    (*this->_mon[this->monster_num].it_skill).show(pa,(this->_player1->getX()-1)*32,(this->_player1->getY()-0.4)*32);
                    this->_player1->setX(buffx);
                    this->_player1->setY(buffy);

                    this->_player1->injured((*(this->_mon[this->monster_num].it_skill)).get_harm()+ this->_mon[this->monster_num].getatt());
                    this->_player1->death();
                    if(this->_player1->getstate() == 0)
                    {
                        this->now_interface = 2;
                        this->_mon[this->monster_num].setState(1);
                        this->_mon[this->monster_num].setsence(1);
                        this->_mon[this->monster_num].setHPnow(this->_mon[this->monster_num].getallHP());
                        this->_player1->setHPnow(5);
                        this->_player1->setState(1);
                        this->_player1->setsence(1);
                        this->fd->changeturn();
                    }
                    Sleep(100);
                }
                else if(this->_mon[this->monster_num].getsence() == 4)
                {
                    this->fd->changeturn();
                    this->_mon[this->monster_num].setsence(2);
                }

        }


            this->_player1->show(pa);
            this->_mon[this->monster_num].show(pa);

            break;

    case 4:
        QImage victor;
        victor.load(":map/victory.png");
        pa->drawImage(0,0,victor);
        break;
    }
    //this->repaint();
    this->_bag.show(pa);
    this->_money_sys.show(pa);




    QImage quit;
    quit.load(":/pic/quit.png");
    pa->drawImage(1000,0,quit);
    if(this->rd->getstart() == 1)
    {
        this->rd->showpic(pa);
        this->rd->setstart(0);
    }
}

void world::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"x: "<<event->pos().x()<<endl;
     qDebug()<<"y: "<<event->pos().y()<<endl;
      this->rd->return_to_head();
     if(event->pos().x() >= 820 && event->pos().x() <= 840 && event->pos().y() >= 135 && event->pos().y() <= 155 && _bag.opend()){
         _bag.open();
         _money_sys.open();
     }
    if(this->now_interface == 1  )
    {
        if(event->button() == Qt::LeftButton)
        {
            if(event->pos().x() >= 435 && event->pos().x() <= 590 && event->pos().y() >= 365 &&event->pos().y() <= 415){
                this->ld->read(event,*this->_player1);
                this->rd->setmap(this->_player1->getmatt());
                this->now_interface = 2;
            }
        }

        if(event->button() == Qt::LeftButton)//用左键来控制
        {

            if(event->pos().x()>= 415 && event->pos().x()<= 600 && event->pos().y()>= 282 && event->pos().y()<= 340)
            {
                this->now_interface = 2;
            }
        }
        //
    }
    else if(this->now_interface == 2 )
    {
        //this->rd->store(event,*this->_player1);
    }
   // this->repaint();
    if(_bag.opend()){
        if(event->pos().y() >= 380 && event->pos().y() <= 440)
            _n_select += 16;
        else if(event->pos().y() >= 290 && event->pos().y() <= 350)
            _n_select += 8;
        else if(event->pos().y() >= 210 && event->pos().y() <= 265)
            _n_select += 0;
        else
            return;
        for(int i = 0; i < 8; i++){
            if(event->pos().x() >= 230 + 75 * i && event->pos().x() <= 285 + 75 * i){
                _n_select += i;
                //qDebug()<<_n_select<<endl;
                if(event->button() == Qt::LeftButton)
                    _bag.equip(_n_select, _strengthen);
                else if(event->button() == Qt::RightButton){
                    _money_sys.sell(_bag.getType(_n_select));
                    _bag.remove(_n_select);
                }
                _player1->strengthen(_strengthen);
            }
        }
        _n_select = 0;
    }
}

void world::keyPressEvent(QKeyEvent *event)
{
    //const monster &monster1 = ( (*(rd->it_m)).exam_mon(this->_player1->getX(),this->_player1->getY()) );
    //this->_player1->setsence(3);
     this->rd->return_to_head();
    if(this->now_interface == 2 )
    {
        int buffx = this->_player1->getX();
        int buffy = this->_player1->getY();
        //qDebug()<<"x and y"<<this->_player1->getX()<<" "<<this->_player1->getY()<<endl;
        this->_player1->key_move(event);
        this->rd->it_m += this->rd->getmap();
        if((*(rd->it_m)).get_map(this->_player1->getX(),this->_player1->getY() ) == 1)
        {
            this->_player1->setX(buffx);
            this->_player1->setY(buffy);
        }

        this->rd->return_to_head();
        this->npc1->key_move(event);
    }

    static int j=0;

    //qDebug()<<"state"<<this->getstate()<<endl;
    if(event->key() == Qt::Key_X)
    {
        j++;
    }
    if(j%2 == 1)
    {
        this->npc1->setState(1);
    }

    else if(j%2 == 0)
    {
        this->npc1->setState(0);
    }
    //qDebug()<<"J:"<<j<<endl;
    //qDebug()<<"state"<<this->npc1->getstate()<<endl;

    if(event->key() == Qt::Key_L)
    {
        this->now_interface = 3;
        this->_player1->setsence(2);
        //this->monster1.setsence(2);
    }
    //this->repaint();
    if(this->_player1->getsence() == 2)
    {
        this->_player1->attack(event);

    }
    if(this->now_interface == 2)this->rd->store(event,*this->_player1);
    this->m1.turn_manual(event);
    //this->repaint();
    if(event->key() == Qt::Key_B){
        _bag.open();
        _money_sys.open();
    }
}



