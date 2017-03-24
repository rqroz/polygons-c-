#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {
protected:
    double x, y;
public:
    Point();
    Point(const float, const float);

    double getX();
    double getY();

    void setX(float);
    void setY(float);
    void setXY(float, float);

    float abs();
    float distance(const Point&);
    void translate(const float, const float);

    friend istream& operator >> (istream&, Point&);
    friend ostream& operator << (ostream&, const Point&);
    friend bool operator ==(const Point&, const Point&);
    friend Point operator +(const Point&, const Point&);
    friend Point operator -(const Point&, const Point&);
};

#endif // POINT_H
