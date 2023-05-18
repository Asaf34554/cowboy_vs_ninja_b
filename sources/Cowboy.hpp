#pragma once
#include "Character.hpp"


namespace ariel{


    class Cowboy : public Character{
        int _bullets;

        public:
        Cowboy(std::string name,Point location):
            Character(Character(110,location,name,'C')), _bullets(6){}
        ~Cowboy(){
            
        }
        
        void reload(){
            if(isAlive())_bullets = 6;
            else{
                throw std:: runtime_error("The Cowboy is dead");
            }
        }
        bool hasboolets(){
            if(_bullets == 0)return false;
            else return true;
        }
        int NumOfBullets(){
            return _bullets;
        }    
        void shoot(Character * enemy);

    };

}