#pragma once
#include "Character.hpp"


namespace ariel{
    class Ninja : public Character{
        int _speed;
        
        public:
        Ninja(int hitPoint,Point location,const std::string& name,int speed):
            Character(hitPoint,location,name,'N'),_speed(speed){}
        // ~Ninja(){
        // }
        int getSpeed()const{
            return _speed;
        }

        void slash(Character* enemy);
        void move(Character * enemy);
    };
}