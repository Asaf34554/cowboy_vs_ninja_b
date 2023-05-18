#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"


namespace ariel{
    class Team{
        int num_of_warriors;
        Character* _warriors[10];
        Character* _leader;
        
           

        public:

        
            Team(Character* warrior);
            ~Team();




            Team* getTeamA(){
                return this;
            }
            Character* getWarrior(int index){
                return _warriors[index];
            }
            void add(Character* warrior);
            void attack(Team* rival);
            int stillAlive();
            int getNumOfWarriors(){
                return num_of_warriors;
            }
            Character* chooseWhoToHit(Team* rival);
            void setLeader();
            void setTeam(); 
            void print();
    };
}