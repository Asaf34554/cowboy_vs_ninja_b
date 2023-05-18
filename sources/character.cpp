#include <iostream>  
#include <cmath>
#include "Character.hpp"

using namespace std;
using namespace ariel;


double Character:: distance(Character* dst){
    return this->_location.distance(dst->getLocation());
}

void Character:: hit(int hit){
    if(_lifepoint - hit <=0){
        _lifepoint =0;
    }
    else _lifepoint -=hit;
}

bool Character:: is_Alive(){
    if(_lifepoint == 0){
        return false;
    }
    else return true;
}


    
