#include <iostream>
#include <string>

using namespace std;

void Mysetlocale();
void clear();
int menu(char&, int&);
int settings(char&, int&);

int main(){
    Mysetlocale();
    char turn;
    int gridsize, z = 1;
    while(z > 0){
        z = menu(turn, gridsize);
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
int menu(char &fturn, int &gridsize){
    cout << "1 - Новая игра\n"
        << "2 - Настройки\n"
        << "3 - Правила\n"
        << "4 - Выход\n";
    int select; cin >> select;
    switch(select){
        case 1:
            return 0;
        case 2:
            return settings(fturn, gridsize);
        case 3:
            cout << "press enter to continue...\n";
            cin.get();
            return menu(fturn, gridsize);
        case 4:
            return -1;
    }
}

//настройки
int settings(char &fturn, int &gridsize){
    cout << "1 - изменить размер поля\n"
        << "\tтекущий размер: " << gridsize
        << "2 - изменить первого игрока\n"
        << "\tпервый игрок: " << fturn
        << "3 - выход\n:";
    int select; cin >> select;
    switch(select){
        case 1:
            cout << "1 - 3x3\n"
                << "2 - 4x4\n"
                << "3 - 5x5\n"
                << "выберите размер поля:";
            cin >> gridsize;
            if (gridsize > 3 || gridsize < 0){ gridsize = 1; }
            return settings(fturn, gridsize);
        case 2:
            cout << "выберите первого игрока(x, o): ";
            cin >> fturn;
            if (fturn != 'x' && fturn != 'o') { fturn = 'x'; }
            return settings(fturn, gridsize);
        case 3:
            return menu(fturn, gridsize);
        default:
            cout << "invalid input...";
            return -1;
    }
}