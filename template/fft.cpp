#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x,i;
    Point(double x=0,double i=0){
        this->x=x;
        this->i=i;
    }
    Point operator+(const Point&p)const{
        return Point{x+p.x,i+p.i};
    };
    Point operator-(const Point&p)const{
        return Point{x-p.x,i-p.i};
    };
    Point operator*(const Point&p)const{
        return Point{x*p.x-i*p.i,i*p.x-x*p.i};
    };
};

