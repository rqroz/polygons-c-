#ifndef POLIGON_H
#define POLIGON_H
#include "point.h"

#include <iostream>
#include <vector>

using namespace std;

class Polygon {
private:
    const int MAX_SIZE = 100; //holds the maximum number of points allowed
    int size = 0; //holds the maximum number of points to be added
protected:
    vector<Point> points;
public:
    Polygon();

    int getSize();

    bool canAddPoint();
    void addPoint();
    void addPoints(const int);

    void translate(Point&);
    void translate(const float, const float);

    void rotate(const float, Point);

    double area();

    ~Polygon();

    friend istream& operator >> (istream&, Polygon&);
    friend ostream& operator << (ostream&, const Polygon&);
};

#endif // POLIGON_H
