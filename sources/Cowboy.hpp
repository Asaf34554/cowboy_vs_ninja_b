#pragma once
#include "Character.hpp"




namespace ariel{


    class Cowboy : public Character{
        int _bullets;

        public:
        Cowboy(const std::string& name,Point location);
        
        void reload();
        bool hasboolets()const {
           return _bullets !=0;
        }
        int NumOfBullets()const{
            return _bullets;
        }    
        void shoot(Character * enemy);

    };

}