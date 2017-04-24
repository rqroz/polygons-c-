#include "polygon.h"
#include "rectangle.h"

Rectangle::Rectangle(const float x, const float y, const float height, const float width):Polygon(4){
    this->addPoint(x, y);
    this->addPoint(x + width, y);
    this->addPoint(x + width, y - height);
    this->addPoint(x, y - height);
}
