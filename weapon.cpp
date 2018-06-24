#include "weapon.h"

void weapon::intial(string type)
{
    if(type.compare("helmet") == 0){
        this->_hp = 2;
        this->_mp = 0;
        this->_attack = 0;
        this->_defend = 1;
        this->_m_attack = 0;
        this->_m_defend = 10;
        this->_type = 0;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\helmet.png");
        this->_type_name = "helmet";

    }
    else if(type.compare("armour") == 0){
        this->_hp = 10;
        this->_mp = 5;
        this->_attack = 0;
        this->_defend = 3;
        this->_m_attack = 0;
        this->_m_defend = 5;
        this->_type = 1;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\armour.png");
        this->_type_name = "armour";
    }
    else if(type.compare("boots") == 0){
        this->_hp = 2;
        this->_mp = 0;
        this->_attack = 0;
        this->_defend = 2;
        this->_m_attack = 0;
        this->_m_defend = 2;
        this->_type = 2;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\boots.png");
        this->_type_name = "boots";
    }
    else if(type.compare("handguard") == 0){
        this->_hp = 1;
        this->_mp = 0;
        this->_attack = 0;
        this->_defend = 1;
        this->_m_attack = 0;
        this->_m_defend = 1;
        this->_type = 3;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\handguard.png");
        this->_type_name = "handguard";
    }
    else if(type.compare("sword") == 0){
        this->_hp = 0;
        this->_mp = 0;
        this->_attack = 8;
        this->_defend = 0;
        this->_m_attack = 0;
        this->_m_defend = 0;
        this->_type = 4;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\sword.png");
        this->_type_name = "sword";
    }
    else if(type.compare("shield") == 0){
        this->_hp = 5;
        this->_mp = 5;
        this->_attack = 0;
        this->_defend = 10;
        this->_m_attack = 0;
        this->_m_defend = 50;
        this->_type = 5;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\shield.png");
        this->_type_name = "shield";
    }
    else if(type.compare("null") == 0){
        this->_hp = 0;
        this->_mp = 0;
        this->_attack = 0;
        this->_defend = 0;
        this->_m_attack = 0;
        this->_m_defend = 0;
        this->_type = 100;
        this->_pic.load("F:\\qt\\test_rpg\\test_vision1\\pic\\null.png");
        this->_type_name = "null";
    }
    this->_info = object::find(type);
}
