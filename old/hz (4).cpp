#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int size = 5;
	char tex = '-';
	bool horl = true;

	cout << "�������� ������\n";
	cin >> size;

	cout << "�������� ��� �����(������)\n";
	cin >> tex;

	cout << "�������� �����������\n"
		<< "0 - ������������\n"
		<< "1 - ��������������\n";
	cin >> horl;

	while(size > 0){
		if (horl){ cout << tex; }
		else { cout << tex << "\n"; }
		size--;
	}
	return 0;
}
