#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	setlocale(0, "");
	string menu0, menu1, menu2;
	menu0 = "1 - english\n2 - русский\n";
    menu1 = "penicillin\nnecktie\ncapitalization\ncarriage\nplan\npython\nashes\nsynthesis\nsystem\nitemized\nancient\ntrolley\nimage\nrevolution\n";
    menu2 = "пенициллин\nгалстук\nкапитализация\nкарета\nплан\nпитон\nпрах\nсинтез\nсистема\nдробный\nдревний\nдрезина\nобраз\nоборот\n";
	int mode;
    cout << menu0 << ":"; cin >> mode;
    switch(mode){
    case 1:
        cout << menu1;
        break;
    case 2:
        cout << menu2;
        break;
    default:
        cout << "Неверное значение";
        break;
    }
	return 0;
}
