#pragma once
#include "Ship.h"

class Boat : public Ship
{
private:
    int appointment;
    string material;
    string ride_quality;
    int speed;
    int people;

public:
    Boat();
    Boat(ifstream &fin); // с параметром
    ~Boat();
    void Edit();
    void Save(ofstream &fout);
    void Show(ostream &out);
};