#ifndef POLIGON_H
#define POLIGON_H
#include "point.h"

#include <iostream>
using namespace std;

class Polygon {
private:
    const int MAX_SIZE = 100; //holds the maximum number of points allowed
    int size = 0; //holds the maximum number of points to be added
    int counter = 0; //holds the number of points added to the poligon
protected:
    Point *points;
    int *ints;
public:
    Polygon();

    int getSize();
    int getCounter();
    Point* getPoints();

    bool canAddPoint();
    void addPoint();
    void addPoints(int);

    void translate(Point);
    void translate(float, float);

    double area();

    ~Polygon();

    friend istream& operator >> (istream&, Polygon&);
    friend ostream& operator << (ostream&, const Polygon&);
};

#endif // POLIGON_H
