#include "Sailboat.h"

Sailboat::Sailboat()
{
    cout << "+++++++++++++++++++++++++++++++++++ Парусник +++++++++++++++++++++++++++++++++++" << endl;
    try
    {
        cout << "Введите название парусника: " << endl;
        cin.ignore(256, '\n');
        getline(cin, this->name);
        if (name == "")
        {
            throw(string) "Название не может быть пустым.";
        }

        cout << "Введите тип парусника: " << endl;
        cin.ignore(256, '\n');
        getline(cin, this->type);
        if (type == "")
        {
            throw(string) "Тип парусника не может быть пустым.";
        }

        cout << "Выберите назначение парусника |1| - мирный; |2| - военный = " << endl;
        cin >> this->appointment;
        if (this->appointment < 1 || this->appointment > 2)
        {
            throw(string) "Назначение парусника обязательно должно быть выбрано.";
        }

        cout << "Введите длину парусника = " << endl;
        cin >> this->length;
        if (this->length <= 0)
        {
            throw(string) "Длина не может отрицательной или быть нулевой.";
        }

        cout << "Введите максимальную скорость парусника = " << endl;
        cin >> this->speed;
        if (this->speed <= 0)
        {
            throw(string) "Скорость не может равняться нулю или быть отрицательной.";
        }

        cout << "Введите количество экипажа: " << endl;
        cin >> this->people;
        if (this->people <= 0)
        {
            throw(string) "Экипаж парусника не может быть отрицательным или ровняться нулю.";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Sailboat::Sailboat(ifstream &fin)
{
}

Sailboat::~Sailboat()
{
    cout << "Вызван дистрокутор класса Sailboat" << endl;
    system("pause");
}

void Sailboat::Edit()
{
}

void Sailboat::Save(ofstream &fout)
{
    fout << getType() << endl;
    fout << this->name << endl;
    fout << this->type << endl;
    fout << this->appointment << endl;
    fout << this->length << endl;
    fout << this->speed << endl;
    fout << this->people << endl;
}

void Sailboat::Show(ostream &out)
{
    {
        cout << "+++++++++++++++++++++++++++++++++++ Парусник +++++++++++++++++++++++++++++++++++" << endl;
        cout << "Название парусника: " << name << endl;
        cout << "Тип парусника: " << type << endl;
        cout << "Назначение парусника: " << appointment << endl;
        cout << "Длина парусника: " << length << endl;
        cout << "Максимальная скорость парусника: " << speed << endl;
        cout << "Количество экипажа: " << people << endl;
    }
}
