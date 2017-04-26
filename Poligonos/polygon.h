#ifndef POLIGON_H
#define POLIGON_H
#include "point.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @date   Abril, 2017
 * @brief  Classe utilizada para representar um polígono em um plano 2D.
 * @details
 * Considere "tamanho" como sendo o número de vértices/pontos do polígono.
 */
class Polygon {
protected:
    const int MAX_SIZE = 100; /**< Número máximo de vértices permitidos. */
    int size = 0; /**< Tamanho definido do polígono. */
    vector<Point> points; /**< Vetor para guardar os pontos (vértices) do polígono. */
public:
    //! Construtor alternativo.
    /*! @param n Define o tamanho do polígono. */
    Polygon(int);

    int getSize(); /**< Retorna o tamanho do polígono. */

    //! Adiciona um objecto Ponto como novo vértice do polígono.
    /*! @param p Ponto a ser adicionado. */
    void addPoint(Point p);

    /**
     * Cria um objeto Ponto a partir dos paramêtros e o adiciona ao polígono.
     * @param x Coordenada x do ponto a ser adicionado.
     * @param y Coordenada y do ponto a ser adicionado.
     * @see addPoint(Point p)
    */
    void addPoint(const float, const float);

    void translate(Point&); /**< Translada o polígono para (+x, +y), sendo x e y as coordenadas do parâmetro. */
    void translate(const float, const float); /**< Translada o polígono para (+x, +y), sendo x e y os parâmetros. */

    /**
     * Rotaciona o polígono em relação à um ponto.
     * @param degrees O ângulo ao qual o polígono será rotacionado, em graus.
     * @param p Ponto de referência.
    */
    void rotate(const float, Point); /**< de T graus no sentido anti-horário em torno de um ponto. */

    double area(); /**< Retorna a área do polígono. */
    Point center(); /**< Retorna um Ponto que representa o centro de massa do polígono. */

    friend istream& operator >> (istream&, Polygon&);
    friend ostream& operator << (ostream&, const Polygon&);
};

#endif // POLIGON_H
