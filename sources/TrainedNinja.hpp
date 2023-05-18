#pragma once
#include "Ninja.hpp"

using namespace std;
namespace ariel{
    class TrainedNinja : public Ninja{
            

            public:
            TrainedNinja(std::string name,Point location):
                Ninja(120,location,name,12) {}
            ~TrainedNinja(){
                
            }
    };

}
