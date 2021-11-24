#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	int num1, num2, result;
	char op;
	cout << "Введите число а: "; cin >> num1;
	cout << "Введите операцию: "; cin >> op;
	//Определяем действие и кол-во необходимых переменных.
	if (op == 's' || op == 'c'){
		//Дополнительная переменная не требуется
		if(op == 's'){ result = sin(num1); cout << "sin(" << num1 << ")=" << result; }
		else if(op == 'c'){ result = cos(num1); cout << "cos(" << num1 << ")=" << result; }
	}
	else{
		//Необходима дополнительная переменная
		cout << "Введите число b: "; cin >> num2;
		if (op == '+'){ result = num1 + num2; cout << num1 << op << num2 << "=" << result; }
		else if(op == '-'){ result = num1 - num2; cout << num1 << op << num2 << "=" << result; }
		else if(op == '*'){ result = num1 * num2; cout << num1 << op << num2 << "=" << result; }
		else if(op == '/'){ result = num1 / num2; cout << num1 << op << num2 << "=" << result; }
		else if(op == '%'){ result = num1 % num2; cout << num1 << op << num2 << "=" << result; }
		else if(op == '^'){ result = pow(num1, num2); cout << num1 << op << num2 << "=" << result; }
	}
	return 0;
}