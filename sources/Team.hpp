#pragma once
#include "cowboy.hpp"
#include "youngninja.hpp"
#include "trainedninja.hpp"
#include "oldninja.hpp"


namespace ariel{
    class Team{
        int num_of_warriors;
        Character* _warriors[10];
        Character* _leader;
        Character* chooseWhoToHit(Team* rival);
        void setLeader();
        void setTeam();            

        public:
            Team(Character* warrior);
            ~Team();
            void add(Character* warrior);
            void attack(Team* rival);
            int stillAlive();

            void print();
    };
}