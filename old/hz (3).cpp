#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int num, day; string month, res;
	cout << "Выберите месяц: " << "\n"
		<< "1 - Январь" << "\n"
		<< "2 - Февраль" << "\n"
		<< "3 - Март" << "\n"
		<< "4 - Апрель" << "\n"
		<< "5 - Май" << "\n"
		<< "6 - Июнь" << "\n"
		<< "7 - Июль" << "\n"
		<< "8 - Август" << "\n"
		<< "9 - Сентябрь" << "\n"
		<< "10 - Октябрь" << "\n"
		<< "11 - Ноябрь" << "\n"
		<< "12 - Декабрь" << "\n"
		<< ":"; cin >> num;
	switch(num){
	case 1:
		month = "Января";
		break;
	case 2:
		month = "Февраля";
		break;
	case 3:
		month = "Марта";
		break;
	case 4:
		month = "Апреля";
		break;
	case 5:
		month = "Мая";
		break;
	case 6:
		month = "Июня";
		break;
	case 7:
		month = "Июля";
		break;
	case 8:
		month = "Августа";
		break;
	case 9:
		month = "Сентября";
		break;
	case 10:
		month = "Октября";
		break;
	case 11:
		month = "Ноября";
		break;
	case 12:
		month = "Декабря";
		break;
	default:
		cout << "Такой даты не существует";
		return 0;
	}

	cout << "Выберите день: "; cin >> day;
	switch(num){
	case 2:
		if (day <= 28){ cout << day << "-ое " << month; }
		else { cout << "Такой даты не существует"; }
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day <= 31){ cout << day << "-ое" << month; }
		else { cout << "Такой даты не существует"; }
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day <= 30){ cout << day << "-ое" << month; }
		else { cout << "Такой даты не существует"; }
		break;
	}
	return 0;
}
