#include <iostream>
#include <string>
#include <time.h>

#define clear system("cls")

using namespace std;

int questQty = 5; //���-�� ��������
int missQty = 3; //���-�� ������
string _;

string valerr = "invalid input...";
//������ � ����������
string qa[15][5] = {

	//{"������", "���������� �����", "������������ �����", "������������ �����", "������������ �����"}
	{"�� ������ ������?", "��", "���", "�� ����", "��"},
	{"������� ������ � ��������?", "0", "�����", "��", "�� ���� �� ���� �������?"},
	{"2+2?", "4", "~4", "-4", "+4"},
	{"��?", "��", "!��", "��", "!��"},
	{"�� ��������� ����� �� ����������?", "��", "!���", "��", "�����"},
	{"������� �� � �?", "1000", "200", "2000", "10��"},
	{"������� ���� � �����?", "5", "6", "2", "-1"},
	{"������� ������� � 9-������� ����?", "36", "34", "9", "-34"},
	{"������� ����� ����?", "�����������", "���������", "������������", "��������������"},
	{"������� ������ � �����?", "1", "~345", "!1", "4"},
	{"���������� ����?", "�", "��", "�", "�/�"},
	{"�����?", "����", "�� ����", "��", "�����"},
	{"�� ������ ������.", "��", "��", "���", "67"},
	{"������� � ��?", "���������", "����������", "����", "�������"},
	{"������?", "�����", "!������", "��", "�����"}
};

int usedQuest[15]{};

int menu();
int settings();
void game();
int randnum(int);
int randnum(int, int);

int main() {
	//setlocale(0, "");
	system("chcp 1251");
	switch (menu())
	{
	case 0:
		return 0;
		break;
	case 1:
		game();
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
	clear;
	cout << "1 - ����� ����\n"
		<< "2 - ���������\n"
		<< "3 - �������\n"
		<< "4 - �����\n"
		<< ": ";
	int select; cin >> select;
	switch (select)
	{
	case 1:
		clear;
		return 1;
		break;
	case 2:
		return settings();
		break;
	case 3:
		clear;
		cout << "�������:\n"
			<< "1. ��������� ������ ����� 1;\n"
			<< "2. � ���������� ����� ������� ���-�� �������� � ������� ������ �� ���;\n"
			<< "3. ����� ������ �� ������ �� ����������;\n"
			<< "4. � ��������� ���������� ����� 15 ��������, ��������� ������� ���������� ���� �������;\n"
			<< "5. ��� ������!\n\n"
			<< "������� ����� ������ ��� ������:\n";
		cin >> _;
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
	clear;
	cout << "1 - �������� ���������� ��������:\n"
		<< "\t������� ���������� ��������: " << questQty << "\n"
		<< "2 - �������� ���������� ������:\n"
		<< "\t������� ���������� ������: " << missQty << "\n"
		<< "3 - ���������\n"
		<< ": ";
	int select, tmp;
	cin >> select;
	switch (select)
	{
	case 1:
		clear;
		cout << "����� ���������� ��������: "; cin >> tmp;
		if (tmp > 15) { questQty = 15; }
		else if (tmp < 1) { questQty = 1; }
		else { questQty = tmp; }
		return settings();
		break;
	case 2:
		clear;
		cout << "����� ���������� ������: "; cin >> tmp;
		if (tmp > 15) { missQty = 15; }
		else if (tmp < 0) { missQty = 1; }
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

void game() {
	srand(time(0));
	int turns = 1, questid;
	bool nextQuest = true;
	string select;

	//����� ���������� �������
	while (turns <= questQty) {
		if (nextQuest) {
			questid = randnum(15);
			for (int i = 0; i < 15; i++) {
				if (usedQuest[i] == 0) { usedQuest[i] = questid; break; }
				else if (usedQuest[i] == questid) { questid = randnum(15); i = 0; }
			}
		}

		//����� �������
		cout << qa[questid][0] << "\n\n";

		//����� ��������� ������
		//�������� ������ <<=====================================================#
		for (int i = 1; i < 5; i++) {
			cout << i << " - " << qa[questid][i] << "\n";
		}
		cout << "\n" << ":";

		//���� ������
		cin >> select;
		clear;

		//�������� ������
		//���������� <<===========================================================#
		if (select == qa[questid][1]) {
			cout << "����� ������" << "\n\n";
			nextQuest = true;
			turns++;
		}
		else {
			missQty--;
			cout << "����� �� ������\n"
				<< "�������� �������: " << missQty << "\n\n";
			nextQuest = false;
		}

		if (missQty <= 0) { break; }
	}
}

int randnum(int maxrnd) {
	return rand() % maxrnd;
}

int randnum(int maxrnd, int minrnd) {
	return rand() % maxrnd + minrnd;
}

/*
cout << "ng";

clear;

int q = randnum(15);

cout << qa[q][0] << "\n";

for (int i = 1; i < 5; i++) {
	cout << i << " - " << qa[q][i] << "\n";
}

cout << ": ";

string select; cin >> select;

if (select == qa[q][1]) { cout << "+"; }
else { cout << "-"; }

#--------------------------------------------

printf("%i - %s\n",i, qa[questid][i]);
*/