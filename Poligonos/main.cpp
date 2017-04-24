#include <iostream>
#include "point.h"
#include "polygon.h"
#include "rectangle.h"
#include <cmath>

using namespace std;

int main()
{
    Rectangle rec(0, 0, 3, 4);
    cout << "Retangulo: " << rec;
    cout << "Area do retangulo: " << rec.area() << "\n\n";

    rec.translate(-3, 4);
    cout << "Retangulo transladado: " << rec;
    cout << "Area do retangulo apos translado em (-3, 4): " << rec.area() << "\n\n";

    double pi = acos(-1);
    float angle = (float) 30 / 180.0 * pi;
    rec.rotate(angle, rec.center());
    cout << "Area do retangulo apos rotacao: " << rec.area() << "\n\n";

    cout << "Como nenhuma das operações alteram as dimensões do poligono, a área do retângulo será sempre a mesma.\n\n";
}
