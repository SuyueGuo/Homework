#include "attribute.h"

attribute::attribute()
{
    for(int i=0;i<=5;i++)
    {
        this->_real[i] = 0;
    }
}

void attribute::loadAll(QString path)
{
    this->all.load(path);
}

void attribute::move(int direction, int steps)
{
    if(_direc != direction){
        _steps = 1;
        _direc = direction;
    }
    switch (direction){
        case 1:
            this->_posY += steps;
            break;
        case 4:
            this->_posY -= steps;
            break;
        case 2:
            this->_posX -= steps;
            break;
        case 3:
            this->_posX += steps;
            break;
    }
    //this->now = all.copy(QRect(_steps*Character::GRID_SIZE, _direc*Character::GRID_SIZE, 1*Character::GRID_SIZE, 1*Character::GRID_SIZE));
    _steps++;
    _steps = _steps % 4;
    qDebug()<<"x:"<<_posX<<"  y:"<<_posY<<endl;
}



void attribute::LVup()
{
    if(_EXPnow < _EXP)
           return;
    this->_LV++;
    if(_LV <= 3){
         this->_attack += 2;
    }
    else{
        this->_attack += 1;
    }

    if(_LV<=7){
        this->_HP += 8;
    }
    else
    {
        this->_HP += 5;
    }
    this->_HPnow = _HP;
    this->_MP += 2;
    this->_MPnow = _MP;
    this->_EXPnow = 0;
    if(_LV<=6){
        this->_EXP += 6;
    }
    else if(_LV<=8){
        this->_EXP += 12;
    }
    else {
        this->_EXP += 20;
    }


    if(_LV <= 3){
        this->_defend += 3;
    }
    else if(_LV<5){
        this->_defend+=2;
    }
    else{
        this->_defend+=1;
    }


}

void attribute::injured(int n_attack)
{
    int inj = n_attack - ( this->_real[4]> this->_defend ?  this->_real[4] : this->_defend);
    if(inj<=0) inj = 1;
    this->_HPnow -= inj;
}

void attribute::healed(int HP)
{
    this->_HPnow += HP;
    if(_HP<_HPnow)
        _HPnow = _HP;
}

void attribute::addEXP(int e)
{
    this->_EXPnow += e;
    if(this->_EXPnow >= this->_EXP)
        this->LVup();
}

void attribute::death()
{
    if(this->_HPnow<=0)
    {
        this->_state = 0;
    }
}

void attribute::strengthen(int str[])
{
    _real[0] = this->_HP + str[0];
    _real[1] = this->_MP + str[1];
    _real[2] = this->_attack + str[2];
    _real[3] = this->_m_attack + str[3];
    _real[4] = this->_defend + str[4];
    _real[5] = this->_m_defend + str[5];
    qDebug()<<"attack:"<<_real[2]<<endl;
}
