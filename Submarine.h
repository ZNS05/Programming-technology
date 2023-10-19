#pragma once
#include "Ship.h"

class Submarine : public Ship
{
private:
    int length;
    int wight;
    int people;
    int time;
    int speed;
    string arms;

public:
    Submarine();
    Submarine(ifstream &fin); // с параметром
    ~Submarine();
    void Edit();
    void Save(ofstream &fout);
    void Show(ostream &out);
};