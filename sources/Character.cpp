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

string Character :: print(){

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

Character& Character :: operator=(const Character& other){
    if(this == &other) return *this;
    this->_location = other._location;
    this->_lifepoint = other._lifepoint;
    this->_name = other._name;
    this->_type = other._type;
    this->_use = false;
    return *this;
}


    
