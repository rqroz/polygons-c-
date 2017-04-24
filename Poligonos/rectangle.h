#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
#include "polygon.h"

class Rectangle: public Polygon {
public:
    Rectangle(const float, const float, const float, const float);
};

#endif // RECTANGLE_H
