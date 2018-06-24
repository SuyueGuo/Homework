#include"object.h"
pair<string,object> pairArray[] =
{
    make_pair("null",object("null")),
    make_pair("helmet",object("stone")),
    make_pair("armour",object("armour")),
    make_pair("boots",object("boots")),
    make_pair("handguard",object("handguard")),
    make_pair("sword",object("sword")),
    make_pair("shield",object("shield"))
};

map<string,object> object::GAME_OBJECT_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));

object::object(string type)
{
    this->_type = type;
}

object object::find(string type){
    map<string,object>::iterator ob;
    ob = object::GAME_OBJECT_SET.find(type);
    if (ob==object::GAME_OBJECT_SET.end()){

       cout<<"Error: cannot find object"<<endl;
       return object();
    }
    else{
        return ob->second;
    }
}

