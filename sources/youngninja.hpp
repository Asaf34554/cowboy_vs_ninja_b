#pragma once
#include "ninja.hpp"

using namespace std;
namespace ariel{
    class YoungNinja : public Ninja{
            
            public:
            YoungNinja(std::string name,Point location):
                Ninja(100,location,name,14) {}
            ~YoungNinja(){
                
            }
    };

}

