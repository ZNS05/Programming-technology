#include "Boat.h"

Boat::Boat()
{
    cout << "+++++++++++++++++++++++++++++++++++ Катер +++++++++++++++++++++++++++++++++++" << endl;
    try
    {
        cout << "Выберите назначение парусника |1| - мирный; |2| - военный = " << endl;
        cin >> this->appointment;
        if (this->appointment < 1 || this->appointment > 2)
        {
            throw(string) "Назначение парусника обязательно должно быть выбрано.";
        }

        cout << "Введите материал из которого состоит судно: " << endl;
        cin.ignore(256, '\n');
        getline(cin, this->material);
        if (material == "")
        {
            throw(string) "Название не может быть пустым.";
        }

        cout << "Введите ходовые качества судна: " << endl;
        cin.ignore(256, '\n');
        getline(cin, this->ride_quality);
        if (ride_quality == "")
        {
            throw(string) "Ходовые качества не могут отсутствовать.";
        }

        cout << "Введите максимальную скорость подводной лодки под водой = " << endl;
        cin >> this->speed;
        if (this->speed <= 0)
        {
            throw(string) "Скорость не может равняться нулю или быть отрицательной.";
        }

        cout << "Введите количество экипажа: " << endl;
        cin >> this->people;
        if (this->people <= 0)
        {
            throw(string) "Экипаж катера не может быть отрицательным или ровняться нулю.";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Boat::Boat(ifstream &fin)
{
}

Boat::~Boat()
{
    cout << "Вызван дистрокутор класса Boat" << endl;
    system("pause");
}

void Boat::Edit()
{
}

void Boat::Save(ofstream &fout)
{
    fout << getType() << endl;
    fout << this->appointment << endl;
    fout << this->material << endl;
    fout << this->ride_quality << endl;
    fout << this->speed << endl;
    fout << this->people << endl;
}

void Boat::Show(ostream &out)
{
    {
        cout << "+++++++++++++++++++++++++++++++++++ Катер +++++++++++++++++++++++++++++++++++" << endl;
        cout << "Ширина лодки : " << appointment << endl;
        cout << "Экипаж : " << material << endl;
        cout << "Время под водой : " << ride_quality << endl;
        cout << "Скорость : " << speed << endl;
        cout << "Вооружение : " << people << endl;
    }
}
