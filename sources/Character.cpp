#include <iostream>  
#include <cmath>
#include "Character.hpp"

using namespace std;
using namespace ariel;






double Character:: distance(Character* dst){
    return this->_location.distance(dst->getLocation());
}

void Character:: hit(int hit){
    if(hit < 0){
        throw invalid_argument("Hit cant be smaller then 0");
    }
    if(_lifepoint - hit <=0){
        _lifepoint =0;
    }
    else _lifepoint -=hit;
}

bool Character:: isAlive(){
    if(_lifepoint == 0){
        return false;
    }
    else return true;
}

Character& Character::operator=(Character&& other) noexcept
{
    if (this != &other)  {
        _location = std::move(other._location);
        _lifepoint = other._lifepoint;
        _name = std::move(other._name);
        _type = other._type;
        _use = other._use;

        other._lifepoint = 0; 
        other._use = false;
    }
    return *this;
}

Character Character :: operator=(const Character& other){
    if(this == &other) return *this;
    this->_location = other._location;
    this->_lifepoint = other._lifepoint;
    this->_name = other._name;
    this->_type = other._type;
    this->_use = false;
    return *this;
}


    
