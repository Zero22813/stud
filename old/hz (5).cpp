#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int type, size = 5;
	char tex = '-';

	cout << "1 - �����\n"
		<< "2 - �������\n"
		<< "�������� ������:"; cin >> type;

	switch(type){
	case 1: //�����
		bool horl;

		cout << "�������� ������:"; cin >> size;

		cout << "�������� ��� ��������(������):"; cin >> tex;

		cout << "�������� �����������\n"
			<< "0 - ������������\n"
			<< "1 - ��������������\n";
		cin >> horl;

		while(size > 0){
			if (horl){ cout << tex; }
			else { cout << tex << "\n"; }
			size--;
		}
		break;
	case 2: //�������
		bool fill;

		cout << "�������� ������:"; cin >> size;

		cout << "�������� ��� ��������(������):"; cin >> tex;

		cout << "�������� ����������\n"
			<< "0 - �� ���������\n"
			<< "1 - ���������\n";
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
		cout << "�������� ��������";
		break;
	}
	return 0;
}
