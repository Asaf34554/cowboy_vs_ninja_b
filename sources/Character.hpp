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

        Character(int hitpoint,Point location,const std::string& name,char type):
            _lifepoint(hitpoint),_location(location),_name(name),_type(type), _use(false){}
        
        Character(const Character& other):
            _lifepoint(other._lifepoint),_location(other._location),_name(other._name),_type(other._type),_use(false){}

        Character(Character&& other) = delete;      
        virtual ~Character() = default;

        Character& operator = (Character&& other) = delete;

        Character& operator = (const Character& other);

        void setUse(bool use){
            _use = use;
        }
        bool inUse()const{
            return _use;
        }
        std::string getName()const{
            return _name;
        }
        Point getLocation()const{
            return _location;
        }
        int lifePoint()const {
            return _lifepoint;
        }
        char getType()const {
            return _type; 
        }
        void setLocation(Point lock){
            _location = lock;
        }
        std:: string print();
        bool isAlive();
        double distance(Character * dst);
        void hit(int hit);



    };

}