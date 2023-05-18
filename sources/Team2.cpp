#include "Team2.hpp"

using namespace std;
using namespace ariel;



void Team2::attack(Team* rival){
    if(rival == NULL){
        throw invalid_argument("The  emeny team is null");
    }
    if(this->stillAlive() == 0){
        throw runtime_error("The all team is dead");
    }
    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }
    this->setLeader();
    Character * enemy = this->chooseWhoToHit(rival);
    for (size_t i = 0; i < this->getNumOfWarriors(); i++)
    {
        if(this->getWarrior(i)->getType() == 'C' && this->getWarrior(i)->isAlive()){
            Cowboy* attacker = (Cowboy*)this->getWarrior(i);
            if(attacker->hasboolets())attacker->shoot(enemy);
            else attacker->reload();
        }
        else if(this->getWarrior(i)->getType() == 'N' && this->getWarrior(i)->isAlive()){
            Ninja* attacker = (Ninja*)this->getWarrior(i);
            if(attacker->distance(enemy) <= 1)attacker->slash(enemy);
            else attacker->move(enemy);
        }
        if(enemy->isAlive() == false){
            if(rival->stillAlive() == 0){
                return;
            }
            enemy = this->chooseWhoToHit(rival);
        }
    }
}

void Team2:: print(){
    cout<< "\n***********TEAM**********"<<endl;
    for(int i =0;i<this->getNumOfWarriors();++i){
        if(this->getWarrior(i)->getType() == 'C'){
            cout << this->getWarrior(i)->print() <<endl;
            cout << "---------"<<endl;
        }
        if(this->getWarrior(i)->getType() == 'N'){
            cout << this->getWarrior(i)->print() <<endl;
            cout << "---------"<<endl;
        }
        
    }
    cout<< "************************"<<endl;
}