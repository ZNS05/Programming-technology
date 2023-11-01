#pragma once
#include "Ship.h"

class Sailboat : public Ship
{
private:
    string name;
    string type;
    int appointment;
    int length;
    int speed;
    int people;

public:
    Sailboat();
    Sailboat(ifstream &fin); // с параметром
    ~Sailboat();
    Sailboat(const Sailboat &other); // конструктор копирования
    void Edit();
    void Save(ofstream &fout);
    void Show(ostream &out);
};