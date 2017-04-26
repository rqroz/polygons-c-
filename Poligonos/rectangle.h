#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
#include "polygon.h"

/**
 * @date   Abril, 2017
 * @brief  Classe utilizada para representar um retângulo em um plano 2D.
 *
 * Esta classe é filha da classe Polygon.
 */
class Rectangle: public Polygon {
public:
    //! Construtor alternativo
    /**
     * Define o tamanho do polígono como sendo 4 (quatro vértices) e sua posição a partir dos parâmetros.
     * @param x Posição x do vértice superior esquerdo no plano 2D
     * @param y Posição y do vértice superior esquerdo no plano 2D
     * @param height Altura do Retângulo
     * @param width Largura do Retângulo
    */
    Rectangle(const float x, const float y, const float height, const float width);
};

#endif // RECTANGLE_H
