#ifndef LOAD_INTERFACE_H
#define LOAD_INTERFACE_H
#include "interface.h"
#include"player.h"
#include<vector>
#include<fstream>//读档
#include<QMouseEvent>
//这个类的登录界面
class load_interface:public interface
{
public:
    load_interface();
    ~load_interface(){};
    void loadinterface(QPainter *pa);
    void read(QMouseEvent *m,player &p1);//读入存档--与mainwindow相连接

private:
    QImage click;
    QImage read_all;//存档的界面
};

#endif // LOAD_INTERFACE_H
