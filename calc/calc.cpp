#include <iostream>
#include <string>

using namespace std;

void Mysetlocale(){
    system("chcp 65001");
    system("cls");
}

void clear(){
    system("cls");
}

double calc(double num1, char op, double num2 = 0){
	if (op == '+'){ return num1 + num2; }
	else if (op == '-') { return num1 - num2; }
	else if (op == '*') { return num1 * num2; }
	else if (op == '/'){
		if(num2 == 0){ cout << "invalid input..."; return -1; }
		else { return num1 / num2; }
	}
	else if (op == '%'){ return (int)num1 % (int)num2; }
	else if (op == '!'){
		double res = 1;
		for (int i = 1; i <= num1; i++){
			res *= i;
		}
		return res;
	}
	else if (op == '^'){
		double res = num1;
		for (int i = 1; i <= num2; i++){
			res *= num1;
		}
		return res;
	}
	else if (op == '<'){
		if (num1 < num2){ return num1; }
		else { return num2; }
	}
	else if (op == '>'){
		if (num1 > num2){ return num1; }
		else { return num2; }
	}
	else{ cout << "invalid input..."; return -1; }
}

int main(){
    Mysetlocale();
    double num1, num2;
    char op;
	cout << "введите num1: "; cin >> num1;
	cout << "введите num2: "; cin >> num2;
	cout << "выберите действие: "; cin >> op;
	clear();
	cout << num1 << op << num2 << "=" << calc(num1, op, num2);
    return 0;
}
