#ifndef MONEY_SYSTEM_H
#define MONEY_SYSTEM_H
#include"system.h"
#include<QPainter>
class money_system: public system
{
public:
    money_system();
    void sell(string type);
    void show(QPainter *pa);
    void save(int num);
    void open();
private:
    bool opend;
    int _playerMoney;
    int _bankMoney;
};

#endif // MONEY_SYSTEM_H
