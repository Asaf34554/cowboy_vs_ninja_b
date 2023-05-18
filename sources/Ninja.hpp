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
            if(this == enemy){
                throw std::runtime_error("The Ninja cant hithimself");
            }
            if(enemy->isAlive() == false){
                throw std::runtime_error("The enemy is dead!");
            }
            if(this->isAlive() == false){
                throw std::runtime_error("This Ninja is allready dead!");
            }
            if(this->distance(enemy) <= 1.0){
                enemy->hit(40);
            }
        }
        void move(Character * enemy){
            Point src = this->getLocation();
            this->setLocation( src.moveTowards(src,enemy->getLocation(),this->_speed));
        }
    };
}