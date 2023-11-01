#include "Submarine.h"

Submarine::Submarine()
{
    cout << "+++++++++++++++++++++++++++++++++++\n        Подводная лодка        \n+++++++++++++++++++++++++++++++++++" << endl;
    try
    {
        setType(3);
        cout << "Введите длину подводной лодки = ";
        cin >> this->length;
        if (!this->length || this->length <= 0)
        {
            throw(string) "Длина лодки равна нулю или отрицательна.";
        }

        cout << "Введите ширину подводной лодки = ";
        cin >> this->wight;
        if (this->wight <= 0)
        {
            throw(string) "Ширина лодки равна нулю или отрицательна.";
        }

        cout << "Введите количество экипажа подводной лодки = ";
        cin >> this->people;
        if (this->people <= 0)
        {
            throw(string) "Количество экипажа не может быть отрицательным или равным нулю.";
        }

        cout << "Введите максимальное время пребывания подводной лодки под водой = ";
        cin >> this->time;
        if (this->time <= 0)
        {
            throw(string) "Время не может равняться нулю или быть отрицательным.";
        }

        cout << "Введите максимальную скорость подводной лодки под водой = ";
        cin >> this->speed;
        if (this->speed <= 0)
        {
            throw(string) "Скорость не может равняться нулю или быть отрицательной.";
        }

        cout << "Введите вооружение подводной лодки: ";
        cin.ignore(256, '\n');
        getline(cin, this->arms);
        if (arms == "")
        {
            throw(string) "Вооружение не может быть пустым.";
        }
        setError(false);
    }
    catch (string err)
    {
        cout << "ERROR: " + err << endl;
        setError(true);
    }
}

Submarine::Submarine(ifstream &fin)
{
    setType(3);
    fin >> this->length >> this->wight >> this->people >> this->time >> this->speed;

    fin.ignore(256, '\n');
    getline(fin, arms);
}

Submarine::~Submarine()
{
    cout << "Вызван деструктор класса Submarine" << endl;
    system("pause");
}

void Submarine::Edit()
{
    try
    {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения:" << endl
             << "[1] Длина" << endl
             << "[2] Ширина" << endl
             << "[3] Экипаж" << endl
             << "[4] Время под водой" << endl
             << "[5] Скорость" << endl
             << "[6] Вооружение" << endl
             << "Ваш выбор: ";
        cin >> index;
        if (index < 1 || index > 6)
        {
            throw(string) "Параметра с данным индексом не существует.";
        }
        cout << "Исходное значение: ";
        switch (index)
        {
        case 1:
            cout << length << endl;
            cout << "Новое значение длины: ";
            cin >> iTmp;
            if (!iTmp || iTmp < 0)
            {
                throw(string) "Длина лодки равна нулю или отрицательна.";
            }
            length = iTmp;
            break;
        case 2:
            cout << wight << endl;
            cout << "Новое значение ширины: ";
            cin >> iTmp;
            if (!iTmp || iTmp < 0)
            {
                throw(string) "Ширина лодки равна нулю или отрицательна.";
            }
            wight = iTmp;
            break;
        case 3:
            cout << people << endl;
            cout << "Новое значение количества экипажа: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Количество экипажа не может быть отрицательным.";
            }
            people = iTmp;
            break;
        case 4:
            cout << time << endl;
            cout << "Новое значение времени под водой: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Время не может быть отрицательным.";
            }
            time = iTmp;
            break;
        case 5:
            cout << speed << endl;
            cout << "Новое значение скорости: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Скорость не может быть отрицательным.";
            }
            speed = iTmp;
            break;
        case 6:
            cout << arms << endl;
            cout << "Новое значение вооружения: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw(string) "Вооружение не может быть пустым.";
            arms = sTmp;
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

void Submarine::Save(ofstream &fout)
{
    fout << getType() << endl;
    fout << this->length << endl;
    fout << this->wight << endl;
    fout << this->people << endl;
    fout << this->time << endl;
    fout << this->speed << endl;
    fout << this->arms << endl;
}

void Submarine::Show(ostream &out)
{
    {
        out << "+++++++++++++++++++++++++++++++++++\n        Подводная лодка        \n+++++++++++++++++++++++++++++++++++" << endl;
        out << "Длина лодки: " << length << endl;
        out << "Ширина лодки: " << wight << endl;
        out << "Экипаж: " << people << endl;
        out << "Время под водой: " << time << endl;
        out << "Скорость: " << speed << endl;
        out << "Вооружение: " << arms << endl;
    }
}
