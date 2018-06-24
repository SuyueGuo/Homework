#include "run_interface.h"
#include"windows.h"

run_interface::run_interface()
{
    this->set_interface(2);
    //QImage sence1 ;
    //sence1.load("F:\\qt\\test_rpg\\test_vision1\\pic\\CastleExample.png");
    //this->_pic.push_back(sence1);
    this->start = false;
    it = this->_pic.begin();
    this->start = 0;
    this->succeed.load(":/pic/store_word.png");

    map_game map0;
    map0.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map0.txt");
    map0.setsx(3);
    map0.setsy(16);
    map0.load_pic(":/map/map0.jpg");
    this->_m.push_back(map0);
    //infile.close();

    map_game map1;
    map1.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map1.txt");
    map1.load_pic(":/map/map1.png");
    map1.setex(2);
    map1.setey(19);
    map1.setsx(16);
    map1.setsy(22);
    this->_m.push_back(map1);

    map_game map2;
    map2.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map2.txt");
    map2.setex(10);
    map2.setey(7);
    map2.setsx(32);
    map2.setsy(16);
    map2.load_pic(":/map/map2.png");
    this->_m.push_back(map2);



    map_game map3;
    //second.set_map(24,0,6); //人一开始就在这个页面，显示的位置
    map3.setex(1);
    map3.setey(13);
    map3.setsx(32);
    map3.setsy(12);
    map3.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map3.txt");
    map3.load_pic(":/map/map3.png");
    this->_m.push_back(map3);

    map_game map4;
    map4.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map4.txt");
    map4.setex(1);
    map4.setey(15);
    map4.setsx(17);
    map4.setsy(13);
    map4.load_pic(":/map/map4.png");
    this->_m.push_back(map4);

    map_game map5;
    map5.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map5.txt");
    map5.setex(5);
    map5.setey(4);
    map5.setsx(25);
    map5.setsy(23);
    map5.load_pic(":/map/map5.png");
    this->_m.push_back(map5);

    map_game map6;
    map6.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map6.txt");
    map6.setex(27);
    map6.setey(3);
    map6.setsx(25);
    map6.setsy(24);
    map6.load_pic(":/map/map6.png");
    this->_m.push_back(map6);

    map_game map7;
    map7.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map7.txt");
    map7.setex(11);
    map7.setey(1);
    map7.setsx(27);
    map7.setsy(20);
    map7.load_pic(":/map/map7.png");
    this->_m.push_back(map7);

    map_game map8;
    map8.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map8.txt");
    map8.setex(19);
    map8.setey(17);
    map8.setsx(6);
    map8.setsy(22);
    map8.load_pic(":/map/map8.png");
    this->_m.push_back(map8);

    map_game map9;
    map9.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map9.txt");
    map9.setex(20);
    map9.setey(22);
    map9.setsx(29);
    map9.setsy(11);
    map9.load_pic(":/map/map9.png");
    this->_m.push_back(map9);

    map_game map10;
    map10.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map10.txt");
    map10.setex(15);
    map10.setey(9);
    map10.setsx(16);
    map10.setsy(24);
    map10.load_pic(":/map/map10.png");
    this->_m.push_back(map10);

    map_game map11;
    map11.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map11.txt");
    map11.setex(15);
    map11.setey(5);
    map11.setsx(14);
    map11.setsy(22);
    map11.load_pic(":/map/map11.png");
    this->_m.push_back(map11);

    map_game map12;
    map12.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map12.txt");
    map12.setex(22);
    map12.setey(23);
    map12.setsx(16);
    map12.setsy(7);
    map12.load_pic(":/map/map12.png");
    this->_m.push_back(map12);

    map_game map13;
    map13.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map13.txt");
    map13.setex(30);
    map13.setey(23);
    map13.setsx(32);
    map13.setsy(5);
    map13.load_pic(":/map/map13.png");
    this->_m.push_back(map13);

    map_game map14;
    map14.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map14.txt");
    map14.setex(4);
    map14.setey(11);
    map14.setsx(32);
    map14.setsy(5);
    map14.load_pic(":/map/map14.png");
    this->_m.push_back(map14);

    map_game map15;
    map15.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map15.txt");
    map15.setex(1);
    map15.setey(6);
    map15.setsx(32);
    map15.setsy(21);
    map15.load_pic(":/map/map15.png");
    this->_m.push_back(map15);

    map_game map16;
    map16.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map16.txt");
    map16.setex(1);
    map16.setey(6);
    map16.setsx(16);
    map16.setsy(16);
    map16.load_pic(":/map/map16.png");
    this->_m.push_back(map16);

    map_game map17;
    map17.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map17.txt");
    map17.setex(16);
    map17.setey(9);
    map17.setsx(16);
    map17.setsy(21);
    map17.load_pic(":/map/map17.png");
    this->_m.push_back(map17);

    map_game map18;
    map18.read_map("F:\\qt\\test_rpg\\test_vision1\\map\\map18.txt");
    map18.setex(17);
    map18.setey(22);
    map18.load_pic(":/map/map18.png");
    this->_m.push_back(map18);



    this->setmap(0);
    this->it_m = this->_m.begin();


}

void run_interface::loadinterface(QPainter *pa)
{
    //vector<QImage>::iterator it;
    //pa->drawImage(0,0,(*it));//画图
    this->return_to_head();
    it_m += this->getmap();
    (*it_m).show(pa);

    (*it_m).show_mon(pa);
    (*it_m).show_npc(pa);
    (*it_m).show_fruit(pa);
    //for(this->(*it_m).it_ = )
    //this->it_m = this->_m.begin();//重新变为头结点
}

void run_interface::showpic(QPainter *pa)
{
    pa->drawImage(400,400,this->succeed);
    //Sleep(1000);
    this->start = 1;
}

void run_interface::store(QKeyEvent *m, player &p1)
{
    if(m->key() == Qt::Key_M)
    {
        ofstream outfile;
        outfile.open("F:\\qt\\test_rpg\\test_vision1\\store1.txt");
        if(outfile.is_open())
        {
            outfile<<p1.getDirec()<<endl;
            outfile<<p1.getSteps()<<endl;
            outfile<<p1.getstate()<<endl;
            outfile<<p1.getX()<<endl;
            outfile<<p1.getY()<<endl;
            outfile<<p1.getLV()<<endl;
            outfile<<p1.getHP()<<endl;
            outfile<<p1.getallHP()<<endl;
            outfile<<p1.getMP()<<endl;
            outfile<<p1.getexp()<<endl;
            outfile<<p1.getexpnow()<<endl;
            outfile<<p1.getatt()<<endl;
            outfile<<p1.getmatt()<<endl;
            outfile<<p1.getdef()<<endl;
            outfile<<p1.getmdef()<<endl;
            outfile<<p1.getcamp()<<endl;
            outfile<<p1.getsence()<<endl;
            outfile<<this->getmap()<<endl;
            this->start = 1;
        }
    }

}

map_game run_interface::change_map(int i)
{
    this->it_m = this->_m.begin();
    it_m += i;
    this->setmap(i);
    return (*it_m);
}
