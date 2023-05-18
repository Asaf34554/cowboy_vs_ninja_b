#pragma once
#include "Team.hpp"


namespace ariel{
    class Team2 : public Team{
        int num_of_warriors;
        Character* warriors[10];


        public:
            Team2(Character* warrior);
            ~Team2();

            
            void add(Character* warrior);
            
            void attack(Team* rival);
            
            int stillAlive(){
                return num_of_warriors;
            }
            void print();

    };
}