#include "Team.hpp"

using namespace std;
using namespace ariel;


Team::Team(Character * warrior){
    if(!warrior){
        throw runtime_error("The Character in net initialize");
    }
    if(warrior->inUse() == true){
        throw runtime_error("The warrior is in anther team");
    }
    warrior->setUse(true);
    num_of_warriors = 1;
    _warriors[0] = warrior;
    _leader = warrior;
}

Team::~Team(){
    for(int i =0;i< this->num_of_warriors;++i){
        delete _warriors[i]; 
    }
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
    for(int i = 1;i<num_of_warriors;i++){
        if((temp=src.distance(_warriors[i]->getLocation())) < check && _warriors[i]->isAlive()){
            _leader = _warriors[i];
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
        _warriors[num_of_warriors] = warrior;
        num_of_warriors +=1;
        // this->setTeam();
    }
}

void Team:: setTeam(){ 
    if(num_of_warriors <= 1){
        return;
    }
    Character* ans[10];
    ans[0] = _warriors[0];
    int temp =1;
    for(int i =1;i<num_of_warriors;++i){
        if(_warriors[i]->getType() == 'C'){
            ans[temp++] = _warriors[i];
        }
    }
    for(int i =1;i<num_of_warriors;++i){
        if(_warriors[i]->getType() == 'N'){
            ans[temp++] = _warriors[i];
        }
    }
    for(int i =0;i <num_of_warriors ; ++i){
        _warriors[i] = ans[i];
    }

}

void Team::attack(Team* rival){
    if(rival == NULL){
        throw invalid_argument("The  emeny team is null");
    }
    if(this->stillAlive() == 0){
        throw runtime_error("The all  team is dead");
    }
    if(rival->stillAlive() == 0){
        throw runtime_error("The all enemy team is dead");
    }
    this->setLeader();
    Character * enemy = this->chooseWhoToHit(rival);
    for (size_t i = 0; i < num_of_warriors; i++)
    {
        if(_warriors[i]->getType() == 'C' && _warriors[i]->isAlive()){
            Cowboy* attacker = (Cowboy*)_warriors[i];
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
    for (size_t i = 0; i < num_of_warriors; i++)
    {
        if(_warriors[i]->getType() == 'N' && _warriors[i]->isAlive()){
            Ninja* attacker = (Ninja*)_warriors[i];
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
    for (size_t i = 0; i < this->num_of_warriors ; i++){
        if(this->_warriors[i]->isAlive())ans++;
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
    for(int i = 0;i<rival->num_of_warriors;++i){
        if((temp=src.distance(rival->_warriors[i]->getLocation())) < check && rival->_warriors[i]->isAlive()){
            ans = rival->_warriors[i];
            check = temp;
        }
    }
    // cout << "The team hit: " << ans->getLocation().print()<<endl;
    return ans;
}

void Team:: print(){
    cout<< "\n***********TEAM**********"<<endl;
    for(int i =0;i<num_of_warriors;++i){
        if(_warriors[i]->getType() == 'C'){
            cout << _warriors[i]->print() <<endl;
            cout << "---------"<<endl;
        }
        
    }
    for(int i =0;i<num_of_warriors;++i){
        if(_warriors[i]->getType() == 'N')
        cout << _warriors[i]->print() <<endl;
        cout << "---------"<<endl;
        
    }
    cout<< "************************"<<endl;
}

