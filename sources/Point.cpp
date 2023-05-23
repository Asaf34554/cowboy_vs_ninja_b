#include <iostream>  
#include <cmath>
#include "Point.hpp"

using namespace std;
using namespace ariel;

Point::Point(){
    _x = 0;
    _y = 0;
}

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

string Point::print(){
    int intx = _x*1000;
    int inty = _y*1000;
    double ansx = intx/1000;
    double ansy = inty/1000;
    string ans = "(" +to_string(ansx) + "," +to_string(ansy) + ")";
    return ans;
}

