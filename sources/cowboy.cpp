#include <iostream>  
#include <cmath>
#include "cowboy.hpp"

using namespace std;
using namespace ariel;

void Cowboy:: shoot(Character* enemy){
    cout << this->NumOfBullets() << endl;
    if(this->hasboolets() == false && this->is_Alive()){
        this->reload();
    }
    else if(this->is_Alive() && this->hasboolets()) {
        enemy->hit(10);
        this->_bullets -=1;
    }
    else return;
}