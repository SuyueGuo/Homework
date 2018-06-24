#include"money_system.h"

money_system::money_system()
{
    this->_playerMoney = 100;
    this->_bankMoney = 0;
    this->opend = 0;
}

void money_system::sell(string type)
{
    if(type.compare("helmet") == 0){
        _playerMoney += 20;
    }
    else if(type.compare("armour") == 0){
        _playerMoney += 50;
    }
    else if(type.compare("boots") == 0){
        _playerMoney += 10;
    }
    else if(type.compare("handguard") == 0){
        _playerMoney += 10;
    }
    else if(type.compare("sword") == 0){
        _playerMoney += 50;
    }
    else if(type.compare("shield") == 0){
        _playerMoney += 50;
    }
}

void money_system::show(QPainter *pa)
{
    if(!this->opend)
        return;
    QRect word(803, 169, 300, 100);
    pa->setPen(Qt::white);
    QString money_show;
    money_show.setNum(this->_playerMoney);
    QFont font("Microsoft YaHei", 10, 75);
    pa->setFont(font);
    pa->drawText(word, money_show);
}

void money_system::save(int num)
{
    _playerMoney -= num;
    _bankMoney += num;
}

void money_system::open()
{
    if(this->opend)
        this->opend = 0;
    else
        this->opend = 1;
}
