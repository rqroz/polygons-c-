#include "point.h"
#include <iostream>
#include <math.h>

using namespace std;

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(const float x, const float y){
    this->setXY(x, y);
}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}

void Point::setX(float x){
    this->x = x;
}

void Point::setY(float y){
    this->y = y;
}

void Point::setXY(float x, float y){
    this->setX(x);
    this->setY(y);
}

float Point::abs(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Point::distance(const Point &p){
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

void Point::translate(const float x, const float y){
    this->x += x;
    this->y += y;
}


//Overloading of operator >> in order to make easy reading possible
istream& operator >> (istream& is, Point& p){
    cout << "informe as coordenadas (format: x y): ";
    is >> p.x >> p.y;
    return is;
}

//Overloading of operator << with similar purpose as explained above
ostream& operator << (ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

//Overloading of the operator equality (==) as a friend function
bool operator ==(const Point& p1, const Point& p2){
    return (p1.x == p2.x) && (p1.y == p2.y);
}

//Overloading of the operator sum (+) as a friend function
Point operator +(const Point& p1, const Point& p2){
    return Point(p1.x + p2.x, p1.y + p2.y);
}

//Overloading of the operator subtraction (-) as a friend function
Point operator -(const Point& p1, const Point& p2){
    return Point(p1.x - p2.x, p1.y - p2.y);
}
