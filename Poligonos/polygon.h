#ifndef POLIGON_H
#define POLIGON_H
#include "point.h"

#include <iostream>
#include <vector>

using namespace std;

class Polygon {
protected:
    const int MAX_SIZE = 100; //holds the maximum number of points allowed
    int size = 0; //holds the maximum number of points to be added
    vector<Point> points;
public:
    Polygon(int);

    int getSize();

    bool canAddPoint();
    void addPoint(Point p);
    void addPoint(const float, const float);

    void translate(Point&);
    void translate(const float, const float);

    void rotate(const float, Point);

    double area();
    Point center();

    ~Polygon();

    friend istream& operator >> (istream&, Polygon&);
    friend ostream& operator << (ostream&, const Polygon&);
};

#endif // POLIGON_H
