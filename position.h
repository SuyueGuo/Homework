#ifndef POSITION_H
#define POSITION_H


class position
{
public:
    position();
     ~position();
     int getx()const{return this->posx;}
     int gety()const{return this->posy;}

     void setx(int i){this->posx = i;}
     void sety(int i){this->posy = i;}

 protected:
     int posx;
     int posy;

};

#endif // POSITION_H
