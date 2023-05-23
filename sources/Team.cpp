#include "Team.hpp"

using namespace std;
using namespace ariel;


Team::Team(Character * warrior){
    if(!warrior){
        throw runtime_error("The Character is not initialize");
    }
    if(warrior->inUse() == true){
        throw runtime_error("The warrior is in another team");
    }
    warrior->setUse(true);
    num_of_warriors = 1;
    _warriors.push_back(warrior);
    _leader = warrior;
}

Team::~Team(){
    for(Character* figther :_warriors){
        delete figther; 
    }
}

Team& Team:: operator=(const Team& other){
    if(this == &other){
        return *this;
    }
    delete _leader;
    _leader = other._leader;
    for(Character * warr : _warriors){
        delete warr;
    }
    for(Character* warr : other._warriors){
        _warriors.push_back(warr);
    }
    return *this;

}


void Team:: setLeader(){
    if(_leader->isAlive() ){
        return;
    }
    if(num_of_warriors <= 1){
        cout << "The team include only a dead leadr" <<endl;
        return;
    }
    Character* ldr = _leader;
    Point src = _leader->getLocation();

    double check = __DBL_MAX__;
    double temp;
    for(Character * led :_warriors){
        if((temp=src.distance(led->getLocation())) < check && led->isAlive()){
            _leader = led;
            check = temp;
        }
    }

}

void Team:: add(Character * warrior){
    if(num_of_warriors == 10){
        throw runtime_error("The team has 10 warrios");
    }
    if(warrior->inUse() == true){
        throw runtime_error("The warrior is in anther team");
    }
    if(warrior->isAlive() == false){
        throw runtime_error("The warrior is dead");
    }
    else{
        warrior->setUse(true);
        _warriors.push_back(warrior);
        num_of_warriors +=1;
        // this->setTeam();
    }
}


void Team::attack(Team* rival){
    if(rival == NULL){
        throw invalid_argument("The  emeny team is null");
    }

    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }
    this->setLeader();
    Character * enemy = this->chooseWhoToHit(rival);
    for (Character * att :_warriors)
    {
        if(att->getType() == 'C' && att->isAlive()){
            Cowboy* attacker = (Cowboy*)att;
            if(attacker->hasboolets())attacker->shoot(enemy);
            else attacker->reload();
            
        }
        if(enemy->isAlive() == false){
            if(rival->stillAlive() == 0){
                return;
            }
            enemy = this->chooseWhoToHit(rival);
        }
    }
    for (Character * att :_warriors)
    {
        if(att->getType() == 'N' && att->isAlive()){
            Ninja* attacker = (Ninja*)att;
            if(attacker->distance(enemy) <=1)attacker->slash(enemy);
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

int Team:: stillAlive(){
    int ans = 0;
    for (Character * alive :_warriors){
        if(alive->isAlive())ans++;
    }
    return ans;
}

Character* Team:: chooseWhoToHit(Team* rival){
    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }

    Character* ans;
    Point src = _leader->getLocation();
    double check = __DBL_MAX__;
    double temp;
    for(Character * enemy :rival->_warriors){
        if((temp=src.distance(enemy->getLocation())) < check && enemy->isAlive()){
            ans = enemy;
            check = temp;
        }
    }
    // cout << "The team hit: " << ans->getLocation().print()<<endl;
    return ans;
}

void Team:: print(){
    cout<< "\n***********TEAM**********"<<endl;
    for(Character * prt : _warriors){
        if(prt->getType() == 'C'){
            cout << prt->print() <<endl;
            cout << "---------"<<endl;
        }
        
    }
    for(Character * prt : _warriors){
        if(prt->getType() == 'N')
        cout << prt->print() <<endl;
        cout << "---------"<<endl;
        
    }
    cout<< "************************"<<endl;
}

