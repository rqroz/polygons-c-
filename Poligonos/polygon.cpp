#include "polygon.h"
#include "point.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

Polygon::Polygon(){
    int n;
    cout << "Criando polígono... ";
    do{
        cout <<"Informe o número de vértices: ";
        cin >> n;
        if(n < 3 || n > this->MAX_SIZE)
            cout << "O número de vértices deve ser um inteiro entre 3 e " << this->MAX_SIZE << "!\n";
    }while(n < 3 || n > this->MAX_SIZE);
    this->size = n;
}

int Polygon::getSize(){
    return this->points.size();
}

void Polygon::addPoint(){
    int remaining_size = this->size - this->points.size();
    if(remaining_size > 0){
        Point tmp;
        cin >> tmp;
        this->points.push_back(tmp);
    }else{
        cout << "Polígono já está completo...\n";
    }
}

void Polygon::addPoints(const int n){
    for(int i=0; (i < n) && (i < this->size); ++i){
        cout << "Ponto " << i + 1 << ": ";
        this->addPoint();
    }
}

void Polygon::translate(Point &pt){
    this->translate(pt.getX(), pt.getY());
}

void Polygon::translate(const float x, const float y){
    for(unsigned int i=0; i < this->points.size(); ++i){
        this->points[i].translate(x, y);
    }
}

void Polygon::rotate(const float rad, Point p){
    float s = sin(rad);
    float c = cos(rad);

    for(unsigned int i = 0; i<this->points.size(); ++i){
        //translate point back to origin
        float xzero = this->points[i].getX() - p.getX();
        float yzero = this->points[i].getY() - p.getY();

        // rotate point
        float xnew = xzero * c - yzero * s;
        float ynew = xzero * s + yzero * c;

        //set point to xnew translated back
        this->points[i].setX(xnew + p.getX());
        this->points[i].setY(ynew + p.getY());
    }
}

double Polygon::area(){
    double sumDP = 0, sumDS = 0;
    int counter = this->points.size();
    for(int i=0; i < counter; ++i){
        Point tmp = this->points[i%counter];
        Point nextTmp = this->points[(i+1)%counter];

        sumDP += tmp.getX() * nextTmp.getY();
        sumDS += tmp.getY() * nextTmp.getX();
    }

    return abs(sumDP - sumDS)/2;
}

Polygon::~Polygon(){}


/* Friend functions (operators overloading) */
istream& operator >> (istream& is, Polygon& p){
    p.points.clear();
    cout << "p size: " << p.size << endl;
    p.addPoints(p.size);
    return is;
}

ostream& operator << (ostream& os, const Polygon& p){
    if(p.points.size() == 0){
        os << "O polígono ainda não foi preenchido...\n";
    }else{
        int size = p.points.size();
        for(int i=0; i <= size; ++i){
            os << p.points[i%size];
            if(i != size) cout << " -> ";
        }
    }
    os << "\n";
    return os;
}
