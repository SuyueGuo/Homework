#include "mainwindow.h"

//#include<QtMultimedia/QMediaPlayer>
//#include<QtMultimedia/QMediaPlaylist>
#include<QCoreApplication>
#include "ui_mainwindow.h"

#include<windows.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1080,810);//改变屏幕的大小
    this->world1 = new world;


    playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile("F:\\qt\\test_rpg\\test_vision1\\music\\roof.mp3"));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    mp31 = new QMediaPlayer;
    mp32 = new QMediaPlayer;
    mp33 = new QMediaPlayer;
    mp31->setMedia (QUrl::fromLocalFile("F:\\qt\\test_rpg\\test_vision1\\music\\login.mp3"));
    mp32->setPlaylist(playlist);
    mp33->setMedia (QUrl::fromLocalFile("F:\\qt\\test_rpg\\test_vision1\\music\\battle.mp3"));

    /*QMediaPlayer *mp3 = new QMediaPlayer;
    mp3->setMedia(QUrl::fromLocalFile("F:\\qt\\test_rpg\\test_vision1\\music\\login.mp3"));
    mp3->setVolume(100);
    mp3->play();*/

    /*monster_move = new QTimer(this);
    connect(monster_move,SIGNAL(timeout()),this,SLOT(control_move()));//timeoutslot()为自定义槽
    //timer2->start(10);
    monster_move->start(800);*/
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter *pa = new QPainter;
    pa->begin(this);
    static int i = 0;
    //i = this->world1->getinterface();
    switch(this->world1->getinterface()){
        case 1:
        if(i == 2 || i == 3 || i == 0)
        {
               mp31->setVolume(100);
               mp31->play();
               mp32->pause();
               mp33->pause();
               i = 1;
        }
        break;
        case 2:
        if(i == 1 || i == 3)
        {
               mp32->setVolume(100);
               mp32->play();
               mp31->pause();
               mp33->pause();
               i = 2;
        }

            break;
        case 3:
        if(i == 2 || i == 1 )
        {
               mp33->setVolume(100);
               mp33->play();
               mp32->pause();
               mp31->pause();
               i = 3;
        }

            break;
    }

    //mp3->stop();
    this->world1->show(pa);
    this->update();
    pa->end();

    delete pa;

}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
  this->world1->mousePressEvent(event);
    this->repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    this->world1->keyPressEvent(event);
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    exit(1);
}
