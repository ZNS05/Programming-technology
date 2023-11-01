#include <iostream>
#include "Keeper.h"
using namespace std;

int main()
{
	// setlocale(LC_ALL, "Russian");
	Keeper Kontener;
	int menu;
	do
	{
		system("cls");
		cout << "----------------------------------" << endl
			 << "               МЕНЮ               " << endl
			 << "----------------------------------" << endl
			 << "Кол-во элементов в контейнере : [" << Kontener.getSize() << "]" << endl
			 << "[1] Добавить элемент" << endl
			 << "[2] Удалить элемент" << endl
			 << "[3] Сохранить данные в файл" << endl
			 << "[4] Загрузить данные из файла" << endl
			 << "[5] Изменить данные элемента" << endl
			 << "[6] Вывести данные из контейнера" << endl
			 << "[0] Выход" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			Kontener.add();
			break;
		case 2:
			Kontener.del();
			break;
		case 3:
			Kontener.save();
			break;
		case 4:
			Kontener.load();
			break;
		case 5:
			Kontener.edit();
			break;
		case 6:
			cout << Kontener;
			break;
		case 0:
			return 0;
		default:
			break;
		}
		/*Меню*/
	} while (true);
}