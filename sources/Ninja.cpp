#include "Ninja.hpp"

using namespace std;
using namespace ariel;

void Ninja::move(Character * enemy){
    Point src = this->getLocation();
    this->setLocation(src.moveTowards(src,enemy->getLocation(),this->_speed));
}
void Ninja::slash(Character* enemy){
    if(this == enemy){
        throw std::runtime_error("The Ninja cant hithimself");
    }
    if(!enemy->isAlive()){
        throw std::runtime_error("The enemy is dead!");
    }
    if(!this->isAlive()){
        throw std::runtime_error("This Ninja is allready dead!");
    }
    if(this->distance(enemy) <= 1.0){
        enemy->hit(40);
    }
}