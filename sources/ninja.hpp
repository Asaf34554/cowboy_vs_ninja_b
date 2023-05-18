#pragma once
#include "Character.hpp"


namespace ariel{
    class Ninja : public Character{
        int _speed;
        
        public:
        Ninja(int hitPoint,Point location,std::string name,int speed):
            Character(hitPoint,location,name,'N'),_speed(speed){}
        ~Ninja(){
            
        }
        int getSpeed(){
            return _speed;
        }

        void slash(Character* enemy){
            if(this->distance(enemy) <= 1.0 && this->is_Alive()){
                enemy->hit(40);
            }
            else if(this->is_Alive()){ 
                move(enemy);
            }

        }
        void move(Character * enemy){
            Point src = this->getLocation();
            this->setLocation( src.moveTowards(src,enemy->getLocation(),this->_speed));
        }
    };
}