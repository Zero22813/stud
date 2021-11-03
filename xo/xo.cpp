#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Mysetlocale();
void clear();
int menu(char&, int&);
int settings(char&, int&);
void nextturn(char&);
int setcord(int);

int main(){
    Mysetlocale();
    char turn = 'x';
    int gridsize = 1, tempA = 1, tempB;
    while(tempA > 0){
        tempA = menu(turn, gridsize);
    }
    if (tempA < 0){ return tempA; }

    //создаем игровое поле
    const int gsize = gridsize + 2;
    char grid[gsize][gsize]{};
    for (int i = 0; i < gsize; i++){
            for (int j = 0; j < gsize; j++){
                grid[i][j] = '.';
            }
        }

    //начало игры
    //не готово
    bool ingame = true, skipturn = false;
    while(ingame){
        clear();
        //вывод поля
        for (int i = 0; i < gridsize + 2; i++){
            for (int j = 0; j < gridsize + 2; j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
        //ход игрока
        cout << "\nход игрока \"" << turn << "\"\n";
        tempA = setcord(gsize);
        tempB = setcord(gsize);
        if (grid[tempA][tempB] == '.'){
            grid[tempA][tempB] = turn;
        }
        else{
            cout << "invalid input...";
            skipturn = true;
        }

        if(!skipturn){ nextturn(turn); ingame = false; }

        //запрет бесконечного цикла
        //потом норм выход сделать
        //ingame = false;
    }

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
        << "\tтекущий размер: " << gridsize << "\n"
        << "2 - изменить первого игрока\n"
        << "\tпервый игрок: " << fturn << "\n"
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

//смена хода
void nextturn(char &turn){
    if (turn == 'x') { turn = 'o'; }
    else { turn = 'x'; }
}

//проверка координат
int setcord(int gsize){
    cout << "введите x: ";
    int cord; cin >> cord;
    if (cord >= gsize || cord < 0){
        cout << "invalid input...";
        return setcord(gsize);
    }
    else{ return cord; }
}