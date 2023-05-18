#include <iostream>  
#include <cmath>
#include "Point.hpp"

using namespace std;
using namespace ariel;

double Point:: distance(Point dst){
   return  sqrt(pow(dst.getX()-this->getX(),2)+pow(dst.getY()-this->getY(),2));
}

Point Point:: moveTowards(Point src,Point dst,double dist){
    if (dist < 0){
        throw invalid_argument("Dinstance is negative");
    }

    if (dist == 0){
        return src;
    }

    else if (dist >= src.distance(dst)){
        return dst;
    }
    double distance = src.distance(dst);
    double len = dist/distance;
    double srcx = src.getX();
    double srcy = src.getY();
    src.setX((1-len)*srcx + len*dst.getX());
    src.setY((1-len)*srcy + len*dst.getY());
    return src;
}

