#pragma once

#include <iostream>

#include "point.hpp"

namespace ariel{

    class Character{
        Point _location;
        int _lifepoint;
        std::string _name;
        char _type;

        public:
        //constructors

        Character(int hitpoint,Point location,std::string name,char type):
            _lifepoint(hitpoint),_location(location),_name(name),_type(type) {}
        
        ~Character(){
            
        }
        
        std::string getName(){
            return _name;
        }
        Point getLocation(){
            return _location;
        }
        int lifePoint(){
            return _lifepoint;
        }
        const char getType(){
            return _type; 
        }
        void setLocation(Point lock){
            _location = lock;
        }
        std:: string print(){

            if(this->is_Alive() && _type == 'N'){
                std:: string ans = "Name: N "+ this->getName() + "\nLife: " + std:: to_string(this->lifePoint()) +"\nLocation: "+this->getLocation().print(); 
                return ans;
            }
            else if(this->is_Alive() && _type == 'C'){
                std:: string ans = "Name: C " + this->getName() + "\nLife: " + std:: to_string(this->lifePoint()) +"\nLocation: "+this->getLocation().print(); 
                return ans;
            }
            else if(_type == 'N'){
                std:: string ans = "Name: N(" + this->getName() +")\nLocation: "+this->getLocation().print(); 
                return ans;
            }
            else {
                std:: string ans = "Name: C(" + this->getName() +")\nLocation: "+ this->getLocation().print(); 
                return ans;
            }

        }
        bool is_Alive();
        double distance(Character * dst);
        void hit(int hit);



    };

}