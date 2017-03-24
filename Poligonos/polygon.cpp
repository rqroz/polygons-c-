#include "polygon.h"
#include "point.h"
#include <iostream>

using namespace std;

Polygon::Polygon(){
    int n;
    cout << "Criando polígono... ";
    do{
        cout <<"Informe o número de vértices: ";
        cin >> n;
        if(n < 3 || n > this->MAX_SIZE)
            cout << "O número de vértices deve ser um inteiro entre 3 e 100!\n";
    }while(n < 3 || n > this->MAX_SIZE);

    cout << "\nsizeof Point: " << sizeof(Point) << "\nsizeof int: " << sizeof(int) << "\n\n";
    this->points = (Point *) calloc(this->size, sizeof(Point));
    this->ints = (int *) calloc(this->size, sizeof(int));
    this->size = n;
}

int Polygon::getSize(){
    return this->size;
}

int Polygon::getCounter(){
    return this->counter;
}

Point* Polygon::getPoints(){
    return this->points;
}

bool Polygon::canAddPoint(){
    return counter < size;
}

void Polygon::addPoint(){
    if(this->canAddPoint()){
        *(this->points + this->counter) = Point();
        cin >> *(this->points + this->counter);

        this->counter++;
    }else{
        cout << "Polígono já está completo...\n";
    }
}

void Polygon::addPoints(const int n){
    for(int i=0; (i < n) && (i < this->size); ++i){
        cout << "Ponto " << this->counter + 1 << ": ";
        this->addPoint();
    }
}

void Polygon::translate(Point &pt){
    this->translate(pt.getX(), pt.getY());
}

void Polygon::translate(const float x, const float y){
    for(int i=0; i < this->counter; ++i){
        (this->points + i)->translate(x, y);
    }
}

double Polygon::area(){
    double sumDP = 0, sumDS = 0;

    for(int i=0; i < this->counter; ++i){
        Point tmp = *(this->points + i%counter);
        Point nextTmp = *(this->points + (i+1)%counter);
        sumDP += tmp.getX() * nextTmp.getY();
        sumDS += tmp.getY() * nextTmp.getX();
    }
    cout << "sumDP: " << sumDP << "\nsumDS: " << sumDS << "\n";
    return (sumDP - sumDS)/2;
}


Polygon::~Polygon(){
//    free(this->points);
}


/* Friend functions (operators overloading) */

istream& operator >> (istream& is, Polygon& p){
    int n, remaining = p.size - p.counter;
    if(remaining > 0){
        cout << "Quantos pontos você deseja adicionar? ";
        do{
            cin >> n;
            if(n < 1 || n > remaining){
                cout << "Por favor, informe um número entre 1 e " << remaining << "...\n";
            }
        }while(n < 1 || n > remaining);

        p.addPoints(n);
    }else{
        cout << "Polígono já está completo...\n";
    }

    return is;
}

ostream& operator << (ostream& os, const Polygon& p){
    if(p.counter == 0){
        os << "O polígono ainda não foi preenchido...\n";
    }else{
        for(int i=0; i < p.counter; ++i){
            os << *(p.points + i) << " -> ";
        }

        if(p.counter > 2)
            os << *(p.points);
    }
    os << "\n";
    return os;
}
