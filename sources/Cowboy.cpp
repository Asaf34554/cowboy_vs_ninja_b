#include <iostream>  
#include <cmath>
#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

void Cowboy:: shoot(Character* enemy){
    if(this == enemy){
        throw runtime_error("The Cowboy cant hithimself");
    }
    if(enemy->isAlive() == false){
        throw runtime_error("The enemy is dead!");
    }
    if(this->isAlive() == false){
        throw runtime_error("This Cowboy is allready dead!");
    }
    if(this->hasboolets()) {
        enemy->hit(10);
        this->_bullets -=1;
    }

    else return;
}