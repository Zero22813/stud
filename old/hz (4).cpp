#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int size = 5;
	char tex = '-';
	bool horl = true;

	cout << "Выберите размер\n";
	cin >> size;

	cout << "Выберите вид линии(символ)\n";
	cin >> tex;

	cout << "Выберите направление\n"
		<< "0 - вертикальная\n"
		<< "1 - горизонтальная\n";
	cin >> horl;

	while(size > 0){
		if (horl){ cout << tex; }
		else { cout << tex << "\n"; }
		size--;
	}
	return 0;
}
