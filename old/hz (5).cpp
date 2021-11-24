#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int type, size = 5;
	char tex = '-';

	cout << "1 - линия\n"
		<< "2 - квадрат\n"
		<< "Выберите фигуру:"; cin >> type;

	switch(type){
	case 1: //Линия
		bool horl;

		cout << "Выберите размер:"; cin >> size;

		cout << "Выберите вид квадрата(символ):"; cin >> tex;

		cout << "Выберите направление\n"
			<< "0 - вертикальная\n"
			<< "1 - горизонтальная\n";
		cin >> horl;

		while(size > 0){
			if (horl){ cout << tex; }
			else { cout << tex << "\n"; }
			size--;
		}
		break;
	case 2: //Квадрат
		bool fill;

		cout << "Выберите размер:"; cin >> size;

		cout << "Выберите вид квадрата(символ):"; cin >> tex;

		cout << "Выберите заполнение\n"
			<< "0 - не заполнять\n"
			<< "1 - заполнять\n";
		cin >> fill;

		int i, j;
		i = 0;
		while (i < size){
			j = 0;
			while (j < size){
				if (i == 0 || i == size - 1){ cout << tex; }
				else if ( fill || (j == 0 || j == size - 1) ) { cout << tex; }
				else { cout << " "; }
				j++;
			}
			cout << "\n";
			i++;
		}
		break;
	default:
		cout << "Неверное значение";
		break;
	}
	return 0;
}
