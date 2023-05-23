#include "SmartTeam.hpp"

using namespace std;
using namespace ariel;



void SmartTeam::attack(Team* rival){
    if(rival == NULL){
        throw invalid_argument("The  emeny team is null");
    }

    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }
    this->setLeader();
    Character * enemy;
    for (Character * att :this->getWarrior())
    {
        enemy = this->chooseWhoToHit(rival,att);
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
      
        if(rival->stillAlive() == 0){
            return;
        }
    }
}

Character* SmartTeam:: chooseWhoToHit(Team* rival,Character* attacker){
    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }
    Character* ans;
    if(attacker->getType() == 'N'){
        Point src = attacker->getLocation();
        double check = __DBL_MAX__;
        double temp;
        for(Character * enemy :rival->getWarrior()){
            if((temp=src.distance(enemy->getLocation())) < check && enemy->isAlive()){
                ans = enemy;
                check = temp;
            }
        }
        return ans;
    }
    else if(attacker->getType() == 'C'){
        for(Character * enemy :rival->getWarrior()){
            int check = 10000;
            int temp;
            if((temp=enemy->lifePoint()) < check && enemy->isAlive()){
                ans = enemy;
                check = temp;
            }
        }
        return ans;
    }
    else return NULL;

}

void SmartTeam:: print(){
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