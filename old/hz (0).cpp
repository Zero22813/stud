#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	cout << "����" << "\n"
		<< "�����" << "\n"
		<< "����" << "\n"
		<< "�����" << "\n"
		<< "������� ��������: ";
	int season; cin >> season;

	if (season == 1){ cout << "������ ���-�� ����� ������ � ������, �� �� ����"; }
	else if(season == 2){ cout << "������ ���-�� ����� ����� � �����, �� �� �����"; }
	else if(season == 3){ cout << "������ ���-�� ����� ������ � ������, �� �� ����"; }
	else if(season == 4){ cout << "������ ���-�� ����� ����� � �����, �� �� �����"; }
	else { cout << "�������� ��������"; }

	return 0;
}