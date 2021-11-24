#include <iostream>
#include <string>
#include <time.h>

#define clear system("cls")

using namespace std;

int ppused = 0;
int questQty = 5; //кол-во вопросов
int missQty = 3; //кол-во ошибок
string _;

string valerr = "invalid input...";
//массив с вопоросами
string qa[15][5] = {

	//{"вопрос", "правильный ответ", "неправильный ответ", "неправильный ответ", "неправильный ответ"}
	{"ВЫ видите вопрос?", "Да", "Нет", "Не знаю", "ОК"},
	{"Сколько перьев у дельфина?", "0", "Много", "Да", "За кого вы меня держите?"},
	{"2+2?", "4", "~4", "-4", "+4"},
	{"ОК?", "ОК", "!КО", "оК", "!кО"},
	{"Вы печатаете текст на клавиатуре?", "Да", "!Нет", "Ок", "Ладно"},
	{"Сколько кг в г?", "1000", "200", "2000", "10ОК"},
	{"Сколько букв в РАСИИ?", "5", "6", "2", "-1"},
	{"Сколько квартир в 9-этажном доме?", "36", "34", "9", "-34"},
	{"Сегодня какой день?", "Сегодняшний", "Вчерашний", "Прошлогодний", "Прошломесячный"},
	{"Сколько спинок у стула?", "1", "~345", "!1", "4"},
	{"Напряжение тока?", "В", "ОМ", "А", "М/С"},
	{"Зачем?", "Надо", "Не надо", "Ок", "Ладно"},
	{"Не точный вопрос.", "ДА", "Да", "Нет", "67"},
	{"Коробка у ПК?", "Системник", "Клавиатура", "Мишь", "Монитор"},
	{"Вопрос?", "Ответ", "!Вопрос", "ОК", "Ладно"}
};

string seed[] {
	"1234",
	"1243",
	"1342",
	"1324",
	"3124",
	"3132",
	"3142",
	"2134",
	"2314",
	"2341",
	"2413",
	"2431",
	"2134",
	"2143",
	"4123",
	"4321",
	"4213",
	"4321",
	"4231",
	"4132",
	"4231",
	"4312"
};

int usedQuest[15] {};

int menu();
int settings();
void game();
int randnum(int);
int randnum(int, int);
int randquest();
void resarr();
char ansout(int);
char ansoutpp(int);

int main() {
	//setlocale(0, "");
	system("chcp 1251");
	resarr();
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
	cout << "1 - Новая игра\n"
		<< "2 - Настройки\n"
		<< "3 - Правила\n"
		<< "4 - Выход\n"
		<< "Режим при входе в правила\n"
		<< "Выбирете в поле пункт из меню: ";
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
		cout << "Правила:\n"
			<< "[1] Вариантов ответа всего 1;\n"
			<< "[2] В настройках можно выбрать кол-во вопросов и попыток ответа на них;\n"
			<< "[3] Время ответа на вопрос не ограничено;\n"
			<< "[4] В викторине содержится всего 15 вопросов, выпадение вопроса определяет ваше везение;\n"
			<< "[5] В игре присутствует помощь искуственного интелекта (50/50), чтобы её активировать введите в поле команду: 50x50;"
			<< "[6] Выиграть просто!\n\n"
			<< "Введите в поле любой символ для выхода: ";
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
	cout << "1 - Изменить количество вопросов:\n"
		<< "\tТекущее количество вопросов: " << questQty << "\n"
		<< "2 - Изменить количество ошибок:\n"
		<< "\tТекущее количество ошибок: " << missQty << "\n"
		<< "3 - Вернуться\n"
		<< ": ";
	int select, tmp;
	cin >> select;
	switch (select)
	{
	case 1:
		clear;
		cout << "Новое количество вопросов: "; cin >> tmp;
		if (tmp > 15) { questQty = 15; }
		else if (tmp < 1) { questQty = 1; }
		else { questQty = tmp; }
		return settings();
		break;
	case 2:
		clear;
		cout << "Новое количество ошибок: "; cin >> tmp;
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
	char rightans;

	//Выбор случайного вопроса
	while (turns <= questQty) {
		if (nextQuest) {
			questid = randquest();
			nextQuest = false;
		}
		
		//вывод вопроса
		cout << qa[questid][0] << "\n\n";

		//вывод вариантов ответа
		if (ppused == 1) {
			rightans = ansoutpp(questid);
			ppused++;
		}
		else {
			rightans = ansout(questid);
		}
		cout << "\n" << "Ожидаю ответ: ";

		//Ввод ответа 
		cin >> select;
		clear;

		//Проверка ответа
		if (ppused == 0 && (select == "50x50" || select == "50х50") ) {
			ppused++;
		}
		else if (ppused != 0 && (select == "50x50" || select == "50х50")) {
			cout << "подсказка уже использована\n";
		}
		else if (select == qa[questid][1] || select[0] == rightans) {
			cout << "Ответ верный!" << "\n\n";
			nextQuest = true;
			turns++;
		}
		else {
			missQty--;
			cout << "Ответ не верный!\n"
				<< "Осталось попыток: " << missQty << "\n\n";
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

//выбор рандомного вопроса
int randquest() {
	int index = randnum(15);
	for (int i = 0; i < 15; i++) {
		if (usedQuest[i] == index) {
			index = randnum(15);
			i = 0;
		}
		else if (usedQuest[i] == 20) {
			usedQuest[i] = index;
			break;
		}
	}
	return index;
}

void resarr() {
	for (int i = 0; i < 15; i++) {
		usedQuest[i] = 20;
	}
}

char ansout(int questid) {
	int index = randnum(22);
	char rightans;
	for (int i = 0; i < 4; i++) {
		if (seed[index][i] == '1') {
			cout << i + 1 << " - " << qa[questid][1] << "\n";
			if (i == 0) { rightans = '1'; }
			else if (i == 1) { rightans = '2'; }
			else if (i == 2) { rightans = '3'; }
			else if (i == 3) { rightans = '4'; }
		}
		else if (seed[index][i] == '2') { cout << i + 1 << " - " << qa[questid][2] << "\n"; }
		else if (seed[index][i] == '3') { cout << i + 1 << " - " << qa[questid][3] << "\n"; }
		else if (seed[index][i] == '4') { cout << i + 1 << " - " << qa[questid][4] << "\n"; }
		else { cout << "rand error...\n"; }
	}
	return rightans;
}

char ansoutpp(int questid) {
	char rightans;
	if (randnum(5) == 1) {
		rightans = '1';
		cout  << "1 - " << qa[questid][1] << "\n";
		cout << "2 - " << qa[questid][randnum(4) + 2] << "\n";
	}
	else {
		rightans = '2';
		cout << "1 - " << qa[questid][randnum(4) + 2] << "\n";
		cout << "2 - " << qa[questid][1] << "\n";
	}
	return rightans;
}