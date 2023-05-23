#pragma once
#include "Team.hpp"


namespace ariel{
    class SmartTeam : public Team{
        
        public:
            SmartTeam(Character* warrior):
                Team(warrior) {}
            void attack(Team* rival);
            void print();
            Character* chooseWhoToHit(Team* rival,Character* attacker);

    };
}