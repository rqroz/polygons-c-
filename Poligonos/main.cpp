#include <iostream>
#include "point.h"
#include "polygon.h"
#include <cmath>

using namespace std;

int main()
{
    Polygon pol;
    cin >> pol;
    cout << pol;
    pol.translate(2, 4);
    cout << pol;
    cout << "Area: " << pol.area() << "\n\n";

    Point p = Point(2, 2);
    double pi = acos(-1);
    float angle = (float) 45 / 180.0 * pi;
    pol.rotate(angle, p);
    cout << pol;
    return 0;
}
