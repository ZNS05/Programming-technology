#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ship
{
private:
    int type;
    bool error;

public:
    void setType(int _type);
    int getType();
    bool isError();
    void setError(bool _error);
    virtual void Save(ofstream &fout) = 0;
    virtual void Edit() = 0;
    virtual void Show(ostream &out) = 0;
    virtual ~Ship() = 0;
};