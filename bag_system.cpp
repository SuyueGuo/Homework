#include "bag_system.h"

bag_system::bag_system()
{
    this->a_bag.load(":/pic/backpackBox.png");
    this->a_equipped.load(":/pic/person_bag.png");
    _num = 24;
    _n_picked = 6;
    _state = 0;
    for(int i = 0; i < 6; i++){
        equipped[i].intial("null");
    }
    picked[0].intial("helmet");
    picked[1].intial("armour");
    picked[2].intial("boots");
    picked[3].intial("handguard");
    picked[4].intial("sword");
    picked[5].intial("shield");
    for(int i = 6; i < 24; i++){
        picked[i].intial("null");
    }
}

void bag_system::initial()
{

}

void bag_system::open()
{
    if(this->_state == 0)
        _state = 1;
    else
        _state = 0;
}

void bag_system::show(QPainter *pa)
{
    if(_state == 0)
        return;
    pa->drawImage(6 * 32, 3 * 32, a_bag);
    if(_n_picked > 16){
        for(int i = 0; i < 8; i++)
            pa->drawImage(230 + i * 75, 380, picked[i + 16].pic());
    }
    if(_n_picked > 8){
        for(int i = 0; i < 8; i++)
            pa->drawImage(230 + i * 75, 290, picked[i + 8].pic());
    }
    if(_n_picked > 0){
        for(int i = 0; i < 8; i++)
            pa->drawImage(230 + i * 75, 210, picked[i].pic());
    }
    pa->drawImage(70, 200, a_equipped);
    pa->drawImage(75, 210, equipped[0].pic());
    pa->drawImage(150, 210, equipped[1].pic());
    pa->drawImage(75, 300, equipped[2].pic());
    pa->drawImage(150, 300, equipped[3].pic());
    pa->drawImage(75, 380, equipped[4].pic());
    pa->drawImage(150, 380, equipped[5].pic());
}

void bag_system::equip(int num, int strengthen[])
{

    if(picked[num].getType() == 100){
           return;
    }
    if(equipped[picked[num].getType()].getType() == 100){
        equipped[picked[num].getType()].intial(picked[num].typeName());
        picked[num].intial("null");
        _n_picked--;
    }
    else if(equipped[picked[num].getType()].getType() == picked[num].getType()){
        string temp = equipped[picked[num].getType()].typeName();
        equipped[picked[num].getType()].intial(picked[num].typeName());
        picked[num].intial(temp);
    }
    for(int i = 0; i < 6; i++){
        strengthen[i] = 0;
    }
    for(int i = 0; i < 6; i++){
        strengthen[0]+=equipped[i].getHp();
        strengthen[1]+=equipped[i].getMp();
        strengthen[2]+=equipped[i].getatt();
        strengthen[3]+=equipped[i].getmatt();
        strengthen[4]+=equipped[i].getdef();
        strengthen[5]+=equipped[i].getmdef();
    }
}

void bag_system::getWeaponRandom()
{
    if(this->_n_picked >= 24)
        return;
    srand(unsigned(time(NULL)));
    int temp = rand() % 6;
    switch(temp){
        case 0:picked[_n_picked].intial("helmet");
                break;
        case 1:picked[_n_picked].intial("armour");
                break;
        case 2:picked[_n_picked].intial("boots");
                break;
        case 3:picked[_n_picked].intial("handguard");
                break;
        case 4:picked[_n_picked].intial("sword");
                break;
        case 5:picked[_n_picked].intial("shield");
                break;
    }
    _n_picked++;
}

string bag_system::getType(int num)
{
    return picked[num].typeName();
}

void bag_system::remove(int num)
{
    picked[num].intial("null");
}
