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
    for (Character * att :this->getWarrior())
    {
        if(att->getType() == 'C' && att->isAlive()){
            Cowboy* attacker = (Cowboy*)att;
            if(attacker->hasboolets())attacker->shoot(enemy);
            else attacker->reload();
        }
        else if(att->getType() == 'N' && att->isAlive()){
            Ninja* attacker = (Ninja*)att;
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
    for(Character * prt :this->getWarrior()){
        if(prt->getType() == 'C'){
            cout << prt->print() <<endl;
            cout << "---------"<<endl;
        }
        if(prt->getType() == 'N'){
            cout << prt->print() <<endl;
            cout << "---------"<<endl;
        }
        
    }
    cout<< "************************"<<endl;
}