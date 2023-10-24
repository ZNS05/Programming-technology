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
    fin >> this->appointment;
    fin.ignore(256, '\n');
    getline(fin, material);
    fin.ignore(256, '\n');
    getline(fin, ride_quality);
    fin >> this->speed >> this->people;
}

Boat::~Boat()
{
    cout << "Вызван дистрокутор класса Boat" << endl;
    system("pause");
}

void Boat::Edit()
{
    try
    {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения: " << endl
             << "[1] Спецификация парусника." << endl
             << "[2] Материал парусника." << endl
             << "[3] Ходовые качества." << endl
             << "[4] Максимальная скорость." << endl
             << "[5] Количество экипажа." << endl;
        cin >> index;
        if (index < 1 || index > 6)
        {
            throw(string) "Параметра с данным индексом не существует";
        }
        cout << "Исходное значение: ";
        switch (index)
        {
        case 1:
            if (appointment == 1)
            {
                cout << "Мирный" << endl;
            }
            else
            {
                cout << "Военный" << endl;
            }
            cout << "Новое значение [1/2]: ";
            cin >> iTmp;
            if (iTmp < 1 || iTmp > 2)
            {
                throw(string) "Назначение должно быть [1/2]";
            }
            appointment = iTmp;
            break;
        case 2:
            cout << material << endl;
            cout << "Новый материал:" << endl;
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
            {
                throw(string) "Материал не может быть пустым.";
            }
            material = sTmp;
            break;
        case 3:
            cout << ride_quality << endl;
            cout << "Новые ходовые характеристики: " << endl;
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
            {
                throw(string) "Ходовые качества не могут быть пустыми.";
            }
            ride_quality = sTmp;
            break;
        case 4:
            cout << speed << endl;
            cout << "Новое значение: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Скорость не может быть отрицательным";
            }
            speed = iTmp;
            break;
        case 5:
            cout << people << endl;
            cout << "Новое значение: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Количество экипажа не может быть отрицательным";
            }
            people = iTmp;
            break;
        default:
            break;
        }
        setError(false);
    }
    catch (string err)
    {
        cout << "ERROR: " + err << endl;
        setError(true);
    }
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
