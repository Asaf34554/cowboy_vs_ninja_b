#pragma once
namespace ariel{


    class Point{
        double __x;
        double __y;


        public:
        Point(){
            __x = 0;
            __y = 0;
        }

        Point(double x,double y):
            __x(x),__y(y){}
        double getX(){
            return __x;
        }
        double getY(){
            return __y;
        }

        void setX(double new_x){
            __x = new_x;
        }

        void setY(double new_y){
            __y = new_y;
        }
        Point operator = (const Point& other){
            if(this == &other)return *this;
            __x = other.__x;
            __y = other.__y;
            return *this;
        }
        std::string print(){
            int intx = __x*1000;
            int inty = __y*1000;
            double ansx = intx/1000;
            double ansy = inty/1000;
            std:: string ans = "(" +std:: to_string(ansx) + "," + std:: to_string(ansy) + ")";
            return ans;
        }

        double distance(Point dst);
        static Point moveTowards(Point src,Point dst,double dist);
    };

}