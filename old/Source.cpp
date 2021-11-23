#include <iostream>
#include <string>

#define clear system("cls")

using namespace std;

int questQty = 5; //кол-во вопросов
int missQty = 3; //кол-во ошибок

string valerr = "invalid input...";

int menu();
int settings();
int game();

int main() {
	setlocale(0, "");
	switch (menu())
	{
	case 0:
		return 0;
		break;
	case 1:
		int game();
		break;
	case -1:
		return -1;
		break;
	default:
		cout << "unknown error...";
		return -159;
		break;
	}
	return 0;
}

int menu() {
	cout << "1 - ng\n"
		<< "2 - settings\n"
		<< "3 - rule\n"
		<< "4 - exit\n"
		<< ": ";
	int select; cin >> select;
	switch (select)
	{
	case 1:
		cout << "ng";
		return 1;
		break;
	case 2:
		return settings();
		break;
	case 3:
		cout << "rules\n";
		return menu();
		break;
	case 4:
		return 0;
		break;
	default:
		cout << valerr;
		return -1;
		break;
	}
}

int settings() {
	cout << "1 - quest qty\n"
		<< "2 - miss qty\n"
		<< "3 - back\n"
		<< ": ";
	int select, tmp;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "new quest qty: "; cin >> tmp;
		if (tmp > 15) { questQty = 15; }
		else if (tmp < 5) { questQty = 5; }
		else { questQty = tmp; }
		return settings();
		break;
	case 2:
		cout << "new miss qty: "; cin >> tmp;
		if (tmp > 15) { missQty = 15; }
		else if (tmp < 5) { missQty = 5; }
		else { missQty = tmp; }
		return settings();
		break;
	case 3:
		return menu();
		break;
	default:
		cout << valerr;
		return -1;
		break;
	}
}

int game() {
	return 0;
}