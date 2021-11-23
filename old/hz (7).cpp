#include <iostream>
#include <string>

#define clear system("cls");

using namespace std;

void tr() {
	int size;
	cout << "Введите высоту треугольника: "; cin >> size;
	bool fill;
	cout << "0 - не заполнять треугольник\n"
		<< "1 - заполнять треугольник\n";
	cin >> fill;
	clear
	if (fill) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= size * 2; j++) {
				if (j == size - i) {
					while (j <= size + i) {
						cout << "#";
						j++;
					}
				}
				else { cout << " "; }
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= size * 2; j++) {
				if (j == 0 || j == size * 2) { cout << " "; }
				else if (j == size - i || j == size + i || i == size - 1) { cout << "#"; }
				else { cout << " "; }
			}
			cout << "\n";
		}
	}
}

void quad() {
	int size;
	cout << "Введите размер квадрата: "; cin >> size;
	bool fill;
	cout << "0 - не заполнять квадрат\n"
		<< "1 - заполнять квадрат\n";
	cin >> fill;
	clear
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (fill || i == 0 || i == size - 1) { cout << "# "; }
			else if (j == 0 || j == size - 1) { cout << "# "; }
			else { cout << "  "; }
		}
		cout << "\n";
	}
}

void pram() {
	int sizex, sizey;
	cout << "Введите размер прямоугольника\n";
	cin >> sizex;
	cin >> sizey;
	bool fill;
	cout << "0 - не заполнять прямоугольник\n"
		<< "1 - заполнять прямоугольник\n";
	cin >> fill;
	clear
		for (int i = 0; i < sizey; i++) {
			for (int j = 0; j < sizex; j++) {
				if (fill || i == 0 || i == sizey - 1) { cout << "# "; }
				else if (j == 0 || j == sizex - 1) { cout << "# "; }
				else { cout << "  "; }
			}
			cout << "\n";
		}
}

void roof(int size, bool osn = 0, bool fill = false) {
	if (fill) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= size * 2; j++) {
				if (j == size - i) {
					while (j <= size + i) {
						cout << "#";
						j++;
					}
				}
				else { cout << " "; }
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= size * 2; j++) {
				if (j == 0 || j == size * 2) { cout << " "; }
				else if (j == size - i || j == size + i || (i == size - 1 && osn)) { cout << "#"; }
				else { cout << " "; }
			}
			cout << "\n";
		}
	}
}

void floor(int size, bool fill = false) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= size * 2 - 1; j++) {
			if (fill) { cout << "#"; }
			else if ((i == 0 && j != 0) || (i == size - 1 && j != 0)) { cout << "#"; }
			else if (j >= size - 1 && j <= size + 1 && i > size - 5) { cout << "#"; } //типо дверь
			else if (j == 1 || j == size * 2 - 1) { cout << "#"; }
			else { cout << " "; }
		}
		cout << "\n";
	}
}

void house() {
	int size;
	cout << "Введите размер дома(не менее 5): "; cin >> size;

	if (size < 5) { size = 5; }
	clear

	roof(size / 2);
	floor(size / 2);
}

void reshota() {
	int size;
	cout << "Введите размер решоты: "; cin >> size;
	clear
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i % 2 == 1 || j % 2 == 1) {
				cout << "# ";
			}
			else { cout << "  "; }
		}
		cout << '\n';
	}
}

void pluse() {
	int size;
	cout << "Введите размер плюсы: "; cin >> size;
	clear
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == size / 2 || j == size / 2) {
				cout << "# ";
			}
			else { cout << "  "; }
		}
		cout << '\n';
	}
}

void hrest() {
	int size;
	cout << "Введите размер хреста: "; cin >> size;
	clear
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == size - 1 - i || j == i) {
				cout << "# ";
			}
			else { cout << "  "; }
		}
		cout << '\n';
	}
}

int main() {
	setlocale(0, "");
	
	int select;
	
	cout << "/tпрога\n"
		<< "1) квадрат\n"
		<< "2) прямоугольник\n"
		<< "3) треугольник\n"
		<< "4) плюс\n"
		<< "5) решота\n"
		<< "6) хрест\n"
		<< "7) дом\n"
		<< "выбери:"; cin >> select;

	switch (select) {
	case 1:
		quad();
		break;
	case 2:
		pram();
		break;
	case 3:
		tr();
		break;
	case 4:
		pluse();
		break;
	case 5:
		reshota();
		break;
	case 6:
		hrest();
		break;
	case 7:
		house();
		break;
	default:
		cout << "invalid command";
		break;
	}

	return 0;
}