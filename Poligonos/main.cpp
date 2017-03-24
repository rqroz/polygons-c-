#include <iostream>
#include "point.h"
#include "polygon.h"

using namespace std;

int main()
{
//    Point p1, p2(4, 1.2);

//    p1.setXY(2,5);
//    p2.translate(5.5, 7.3);

//    cout << "Ponto 1: " << p1 << "\n";
//    cout << "Ponto 2: " << p2 << "\n";
//    cout << "p1 + p2: " << p1 + p2 << "\n";
//    cout << "p1 - p2: " << p1 - p2 << "\n";
//    cout << "Norma p1: " << p1.abs() << "\n";
//    cout << "Norma p2: " << p2.abs() << "\n";

//    cin >> p1;
//    cin >> p2;


//    cout << "Novo ponto 1: " << p1 << "\n";
//    cout << "Novo ponto 2: " << p2 << "\n";

    Polygon pol;
    cin >> pol;
    cout << pol;
    pol.translate(2, 4);
    cout << pol;
    cout << "Area: " << pol.area() << "\n\n";

    return 0;
}
