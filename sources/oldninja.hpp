#pragma once
#include "ninja.hpp"

using namespace std;
namespace ariel{
    class OldNinja : public Ninja{
            

            public:
            OldNinja(std::string name,Point location):
                Ninja(150,location,name,8) {}
            ~OldNinja(){
                
            }
    };

}
