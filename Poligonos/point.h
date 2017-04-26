#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

/**
 * @date   Abril, 2017
 * @brief  Classe utilizada para representar um ponto em um plano 2D.
 */
class Point {
protected:
    double x; /**< Coordenada x do plano */
    double y; /**< Coordenada y do plano */
public:
    //! Construtor padrão
    /*! Define os valores iniciais de x e y como sendo 0. */
    Point();
    //! Construtor alternativo
    /*! Define os valores iniciais de x e y de acordo com os parâmetros recebidos. */
    Point(const float, const float);

    double getX(); /**< Retorna o valor da coordenada x. */
    double getY(); /**< Retorna o valor da coordenada y. */

    void setX(float); /**< Define o valor da coordenada x. */
    void setY(float); /**< Define o valor da coordenada x. */
    void setXY(float, float); /**< Define o valor das coordenadas x e y. */

    float abs(); /**< Retorna a distância do ponto ao centro do sistema de coordenadas. */
    float distance(const Point&); /**< Retorna a distância em relação à outro ponto p. */
    void translate(const float, const float); /**< Translada o ponto em (a,b), sendo a e b números reais (float). */

    friend istream& operator >> (istream&, Point&);
    friend ostream& operator << (ostream&, const Point&);
    friend bool operator ==(const Point&, const Point&);
    friend Point operator +(const Point&, const Point&);
    friend Point operator -(const Point&, const Point&);
};

#endif // POINT_H
