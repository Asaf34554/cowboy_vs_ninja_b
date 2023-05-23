#pragma once
#include <iostream>


namespace ariel{
    class Point{
        double _x;
        double _y;


        public:
        Point();

        Point(double xnum,double ynum):
            _x(xnum),_y(ynum){}
        
        double getX()const{
            return _x;
        }
        double getY()const{
            return _y;
        }

        void setX(double new_x){
            _x = new_x;
        }

        void setY(double new_y){
            _y = new_y;
        }
        std::string print();

        double distance(Point dst);
        static Point moveTowards(Point src,Point dst,double dist);
    };

}