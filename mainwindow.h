#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QKeyEvent>
#include<QDebug>
#include<QTime>
#include<QTimer>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include"interface.h"
#include"load_interface.h"
#include"run_interface.h"
#include"player.h"
#include"attribute.h"
#include"monster.h"
#include"npc.h"
#include"fight_interface.h"
#include"world.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    QMediaPlayer *mp31;
    QMediaPlayer *mp32;
    QMediaPlayer *mp33;
    QMediaPlaylist *playlist;
    Ui::MainWindow *ui;
    QTimer *monster_move;
    world * world1;
//现在的界面 1.登录界面 2.游走界面 3.战斗界面
};

#endif // MAINWINDOW_H
