#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int num, day; string month, res;
	cout << "�������� �����: " << "\n"
		<< "1 - ������" << "\n"
		<< "2 - �������" << "\n"
		<< "3 - ����" << "\n"
		<< "4 - ������" << "\n"
		<< "5 - ���" << "\n"
		<< "6 - ����" << "\n"
		<< "7 - ����" << "\n"
		<< "8 - ������" << "\n"
		<< "9 - ��������" << "\n"
		<< "10 - �������" << "\n"
		<< "11 - ������" << "\n"
		<< "12 - �������" << "\n"
		<< ":"; cin >> num;
	switch(num){
	case 1:
		month = "������";
		break;
	case 2:
		month = "�������";
		break;
	case 3:
		month = "�����";
		break;
	case 4:
		month = "������";
		break;
	case 5:
		month = "���";
		break;
	case 6:
		month = "����";
		break;
	case 7:
		month = "����";
		break;
	case 8:
		month = "�������";
		break;
	case 9:
		month = "��������";
		break;
	case 10:
		month = "�������";
		break;
	case 11:
		month = "������";
		break;
	case 12:
		month = "�������";
		break;
	default:
		cout << "����� ���� �� ����������";
		return 0;
	}

	cout << "�������� ����: "; cin >> day;
	switch(num){
	case 2:
		if (day <= 28){ cout << day << "-�� " << month; }
		else { cout << "����� ���� �� ����������"; }
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day <= 31){ cout << day << "-��" << month; }
		else { cout << "����� ���� �� ����������"; }
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day <= 30){ cout << day << "-��" << month; }
		else { cout << "����� ���� �� ����������"; }
		break;
	}
	return 0;
}
