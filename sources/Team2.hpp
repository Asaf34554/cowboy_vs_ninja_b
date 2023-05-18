#pragma once
#include "Team.hpp"


namespace ariel{
    class Team2 : public Team{
        
        public:
            Team2(Character* warrior):
                Team(warrior) {}
            ~Team2(){}
            void attack(Team* rival);
            void print();
    };
}