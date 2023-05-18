#include "Team.hpp"

using namespace std;
using namespace ariel;


Team::Team(Character * warrior){
    if(!warrior){
        throw runtime_error("The Character in net initialize");
    }

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
    if(_leader->is_Alive() ){
        return;
    }
    if(num_of_warriors <= 1){
        cout << "The team include only a dead leadr" <<endl;
        return;
    }
    cout <<  "New Leader is coming" << endl;
    Character* ldr = _leader;
    Point src = _leader->getLocation();

    double check = __DBL_MAX__;
    double temp;
    for(int i = 1;i<num_of_warriors;i++){
        if((temp=src.distance(_warriors[i]->getLocation())) < check && _warriors[i]->is_Alive()){
            _leader = _warriors[i];
            check = temp;
        }
    }

    if(ldr == _leader){
        cout << "The all team is dead" << endl;
    }
}

void Team:: add(Character * warrior){
    if(num_of_warriors == 10){
        throw runtime_error("The team has 10 warrios");
    }
    else{
        _warriors[num_of_warriors] = warrior;
        num_of_warriors +=1;
        this->setTeam();
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
    for(int i =0;i<num_of_warriors;++i){
        if(_warriors[i]->getType() == 'N'){
            ans[temp++] = _warriors[i];
        }
    }   

}

void Team::attack(Team* rival){
    if(this->stillAlive() == 0){
        return;
    }
    if(rival->stillAlive() == 0){
        cout << "All the enemy members are allready deads" << endl;
        return;
    }
    this->setLeader();
    Character * enemy = this->chooseWhoToHit(rival);
    for (size_t i = 0; i < num_of_warriors; i++)
    {
        if(_warriors[i]->getType() == 'C'){
            Cowboy* attacker = (Cowboy*)_warriors[i];
            attacker->shoot(enemy);
        }
        else if(_warriors[i]->getType() == 'N'){
            Ninja* attacker = (Ninja*)_warriors[i];
            attacker->slash(enemy);
            // cout << "Ninja: "<<attacker->getSpeed()<<endl;
        }
        if(enemy->is_Alive() == false){
            if(rival->stillAlive() == 0){
                cout << "All the enemy members are deads" << endl;
                return;
            }
            cout << "Changeing the one we hit" << endl;
            enemy = this->chooseWhoToHit(rival);
        }
    }
}

int Team:: stillAlive(){
    int ans = 0;
    for (size_t i = 0; i < this->num_of_warriors ; i++){
        if(this->_warriors[i]->is_Alive())ans++;
    }
    return ans;
}

Character* Team:: chooseWhoToHit(Team* rival){
    if(rival->stillAlive() == 0){
        perror("Not alive");
        return NULL;
    }

    Character* ans;
    Point src = _leader->getLocation();
    double check = __DBL_MAX__;
    double temp;
    for(int i = 0;i<rival->num_of_warriors;++i){
        if((temp=src.distance(rival->_warriors[i]->getLocation())) < check && rival->_warriors[i]->is_Alive()){
            ans = rival->_warriors[i];
            check = temp;
        }
    }
    cout << "The team hit: " << ans->getLocation().print()<<endl;
    return ans;
}

void Team:: print(){
    cout<< "\n***********TEAM**********"<<endl;
    for(int i =0;i<num_of_warriors;++i){
        cout << _warriors[i]->print() <<endl;
        cout << "---------"<<endl;
        
    }
    cout<< "************************"<<endl;
}