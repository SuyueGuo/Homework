#include "map_game.h"
//int map_game::num = 1;
//初始化为一号地图

map_game::map_game():num(1)
{
    for(int i=0;i<61;i++)
    {
        for(int j=0;j<50;j++)
        {
            this->_map[i][j] = 0;//变为空
        }
    }
    //NPC test;
    //this->_npc.push_back(test);
    //this->num = i;
}


void map_game::show_npc(QPainter *pa)
{
    for(this->it_p = this->buff_npc.begin(); it_p!=this->buff_npc.end(); this->it_p++)
    {
        //qDebug()<<"------------------"<<endl;
            (*(it_p)).show(pa);
    }
}


void map_game::read_map(char *_file)
{
    ifstream infile;
    infile.open(_file);//F:\\qt\\test_rpg\\test_vision1\\room.txt
    /*first.set_map(40,17,3);
    for(int i=0;i<5;i++)
    {
        first.set_map(36+i,28,5);
    }*/
    int k = 0;
    int buffx,buffy,buffnum;
    int step = 0;
    monster buff_mon;
    object *obbuff;
    npc *buff;
    while( infile>>k && k!= EOF)
    {
        step++;
        switch(step)
        {
            case 1:
                buffx = k;
            break;

            case 2:
                buffy = k;
            break;

            case 3:
               buffnum = k;

               if( buffnum/10 == 3 )
               {
                    buff = new npc;
                    buff->setX(buffx);
                    buff->setY(buffy);
                    //qDebug()<<"----------------"<<buffx<<endl;
                    switch(buffnum%30)
                    {
                    //qDebug()<<"\\\\\\l"<<buffnum;
                        case 1:
                            buff->loadpicnpc(":/pic/npc1.png");
                        break;

                        case 2:
                            buff->loadpicnpc(":/pic/npc2.png");
                        break;

                        case 3:
                            buff->loadpicnpc(":/pic/npc3.png");
                        break;

                        case 4:
                            buff->loadpicnpc(":/pic/npc4.png");
                        break;

                        case 5:
                            buff->loadpicnpc(":/pic/npc5.png");

                        break;

                        case 6:
                            buff->loadpicnpc(":/pic/npc6.png");
                        break;

                    }
                    this->buff_npc.push_back(*buff);
                    delete buff;
               }

               else if( (k/10) == 2)//如果加载了敌人的话
                {
                   buff_mon.setX(buffx);
                    buff_mon.setY(buffy);
                    this->_mon.push_back(buff_mon);
                }

               if( (k/10) == 4)
               {
                   qDebug()<<"-------------------"<<k<<endl;
                   obbuff = new object;
                   obbuff->setx(buffx);
                   obbuff->sety(buffy);
                   if(k%40 == 0)
                   {
                        obbuff->loadpic(":/berry/berry1.png");
                   }
                   if(k%40 == 1)
                   {
                        qDebug()<<"-------------------"<<k<<endl;
                        obbuff->loadpic(":/berry/berry2.png");
                   }
                   if(k%40 == 2)
                   {
                        obbuff->loadpic(":/berry/berry3.png");
                   }
                   if(k%40 == 3)
                   {
                        obbuff->loadpic(":/berry/berry4.png");
                   }
                   if(k%40 == 4)
                   {
                        obbuff->loadpic(":/berry/berry5.png");
                   }
                   if(k%40 == 5)
                   {
                        obbuff->loadpic(":/berry/berry6.png");
                   }
                   this->_fruit.push_back(*obbuff);
                   delete obbuff;
                }
                step = 0;
                this->set_map(buffx,buffy,buffnum);

            break;
        }

    }

    infile.close();


    }

