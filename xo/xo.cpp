#include <iostream>
#include <string>

using namespace std;

void Mysetlocale();
void clear();
int menu(char&, int&, int&);
int settings(char&, int&, int&);

int main(){
    Mysetlocale();
    char turn;
    int gridsize, color, z = 1;
    while(z > 0){
        z = menu(turn, gridsize, color);
    }
    if (z < 0){ return z; }

    return 0;
}

void Mysetlocale(){
    system("chcp 65001");
    system("cls");
}

void clear(){
    system("cls");
}

//главное меню
//дописать правила
int menu(char &fturn, int &gridsize, int &color){
    cout << "1 - Новая игра\n"
        << "2 - Настройки\n"
        << "3 - Правила\n"
        << "4 - Выход\n";
    int select; cin >> select;
    switch(select){
        case 1:
            return 0;
        case 2:
            return settings(fturn, gridsize, color);
        case 3:
            cout << "press enter to continue...\n";
            cin.get();
            return menu(fturn, gridsize, color);
        case 4:
            return -1;
    }
}

//настройки
//потом
int settings(char &fturn, int &gridsize, int &color){
    int select;
    switch(select){
        case 1:
            gridsize = 1;
            break;
        case 2:
            gridsize = 2;
            break;
        case 3:
            gridsize = 3;
            break;
        default:
            cout << "invalid input...";
            return -1;
    }
}