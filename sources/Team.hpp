#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>  


constexpr int WARRIORS = 10;
namespace ariel{
    class Team{
        int num_of_warriors;
        std::vector<Character*> _warriors;
        Character* _leader;
        
           

        public:

        
            Team(Character* warrior);
            Team(const Team& other) = delete;
            Team(Team&& other) = delete;
            Team& operator = (const Team& other);
            Team& operator = (Team&& other) = delete;
            ~Team();





            Team* getTeamA(){
                return this;
            }

            std::vector<Character*> getWarrior()const{
                return _warriors;
            }
            void add(Character* warrior);
            void attack(Team* rival);
            int stillAlive();
            int getNumOfWarriors()const{
                return num_of_warriors;
            }
            Character* chooseWhoToHit(Team* rival);
            void setLeader();
            // void setTeam(); 
            void print();
    };
}