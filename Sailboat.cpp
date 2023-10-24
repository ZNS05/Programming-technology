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
    fin.ignore(256, '\n');
    getline(fin, name);
    fin.ignore(256, '\n');
    getline(fin, type);
    fin >> this->appointment >> this->length >> this->speed >> this->people;
}

Sailboat::~Sailboat()
{
    cout << "Вызван дистрокутор класса Sailboat" << endl;
    system("pause");
}

void Sailboat::Edit()
{
    try
    {
        int index;
        int iTmp;
        string sTmp;
        cout << "Выберите параметр для изменения:" << endl
             << "[1] Название" << endl
             << "[2] Тип" << endl
             << "[3] Экипаж" << endl
             << "[4] Назначение" << endl
             << "[5] Скорость" << endl
             << "[6] Длина" << endl
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
            cout << name << endl;
            cout << "Новое значение: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw(string) "Название не может быть пустым.";
            name = sTmp;
            break;
        case 2:
            cout << type << endl;
            cout << "Новое значение: ";
            cin.ignore(256, '\n');
            getline(cin, sTmp);
            if (sTmp == "")
                throw(string) "Тип не может быть пустым.";
            type = sTmp;
            break;
        case 3:
            cout << people << endl;
            cout << "Новое значение: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Количество экипажа не может быть отрицательным.";
            }
            people = iTmp;
            break;
        case 4:
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
        case 5:
            cout << speed << endl;
            cout << "Новое значение: ";
            cin >> iTmp;
            if (iTmp < 0)
            {
                throw(string) "Скорость не может быть отрицательным";
            }
            speed = iTmp;
            break;
        case 6:
            cout << length << endl;
            cout << "Новое значение: ";
            cin >> iTmp;
            if (!iTmp || iTmp < 0)
            {
                throw(string) "Длина лодки равна нулю или отрицательна";
            }
            length = iTmp;
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
