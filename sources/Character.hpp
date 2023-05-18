#pragma once

#include <iostream>

#include "Point.hpp"

namespace ariel{

    class Character{
        Point _location;
        int _lifepoint;
        std::string _name;
        char _type;
        bool _use;

        public:
        //constructors

        Character(int hitpoint,Point location,std::string name,char type):
            _lifepoint(hitpoint),_location(location),_name(name),_type(type), _use(false){}
        
        Character(const Character& other):
            _lifepoint(other._lifepoint),_location(other._location),_name(other._name),_type(other._type),_use(false){}

        Character(Character&& other) noexcept:
            _location(std::move(other._location)),_lifepoint(other._lifepoint),_name(std::move(other._name)),_type(other._type),_use(other._use){}
        
        ~Character(){ }

        Character& operator = (Character&& other)noexcept;

        Character operator = (const Character& other);

        void setUse(bool use){
            _use = use;
        }
        bool inUse(){
            return _use;
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

            if(this->isAlive() && _type == 'N'){
                std:: string ans = "Name: N "+ this->getName() + "\nLife: " + std:: to_string(this->lifePoint()) +"\nLocation: "+this->getLocation().print(); 
                return ans;
            }
            else if(this->isAlive() && _type == 'C'){
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
        bool isAlive();
        double distance(Character * dst);
        void hit(int hit);



    };

}