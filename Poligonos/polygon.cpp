#include "polygon.h"
#include "point.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

Polygon::Polygon(int n){
    if(n < 3 || n > this->MAX_SIZE){
        cout << "O número de vértices deve ser um inteiro entre 3 e " << this->MAX_SIZE << "!\n";
        exit(0);
    }

    this->size = n;
}

int Polygon::getSize(){
    return this->points.size();
}

void Polygon::addPoint(Point p){
    int remaining_size = this->size - this->points.size();
    if(remaining_size > 0){
        this->points.push_back(p);
    }else{
        cout << "Polígono já está completo...\n";
    }
}

void Polygon::addPoint(const float x, const float y){
    this->addPoint(Point(x,y));
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

Point Polygon::center(){
    unsigned int s = this->points.size();
    float xSum = 0, ySum = 0;
    float den = (this->area()*6);

    for(unsigned int i=0; i < s; ++i){
        float x = this->points[i].getX(), nextX = this->points[(i+1)%s].getX();
        float y = this->points[i].getY(), nextY = this->points[(i+1)%s].getY();
        float commonTerm = (x*nextY - nextX*y);
        xSum += (x + nextX) * commonTerm;
        ySum += (y + nextY) * commonTerm;
    }

    return Point(xSum/den, ySum/den);
}

Polygon::~Polygon(){}


/* Friend functions (operators overloading) */
istream& operator >> (istream& is, Polygon& p){
    Point tmp;

    p.points.clear();

    for(int i=0; i < p.size; ++i){
        cout << "Ponto " << i + 1 << ": ";
        cin >> tmp;
        p.addPoint(tmp);
    }

    return is;
}

ostream& operator << (ostream& os, const Polygon& p){
    if(p.points.size() == 0){
        os << "O polígono ainda não foi preenchido...";
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
