#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	cout << "Лето" << "\n"
		<< "Осень" << "\n"
		<< "Зима" << "\n"
		<< "Весна" << "\n"
		<< "Введите значение: ";
	int season; cin >> season;

	if (season == 1){ cout << "Сейчас что-то между Весной и Осенью, но не Зима"; }
	else if(season == 2){ cout << "Сейчас что-то между Летом и Зимой, но не Весна"; }
	else if(season == 3){ cout << "Сейчас что-то между Осенью и Весной, но не Лето"; }
	else if(season == 4){ cout << "Сейчас что-то между Зимой и Летом, но не Осень"; }
	else { cout << "Неверное значение"; }

	return 0;
}