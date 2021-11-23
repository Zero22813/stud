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

void changeBGcolor(){
    system("color 70");
}

void changeFontColor(){
    system("color 72");
}

int getINTsize(){
    return sizeof(int);
}

int getCHARsize(){
    return sizeof(char);
}

int getDOUBLEsize(){
    return sizeof(double);
}

int getFLOATsize(){
    return sizeof(float);
}

int getBOOLsize(){
    return sizeof(bool);
}

void getmsg(){
    cout << "привет, я функция" << "\n";
}

void drawquad(){
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            cout << "# ";
        }
        cout << "\n";
    }
}

void TimeStop(){
    cout << "жми enter для продолжения...";
    cin.get();
}

int main(){
    Mysetlocale();
    getmsg();
    TimeStop();
    changeBGcolor();
    TimeStop();
    cout << "int: " << getINTsize() << "\n";
    cout << "char: " << getCHARsize() << "\n";
    cout << "double: " << getDOUBLEsize() << "\n";
    changeFontColor();
    cout << "float: " << getFLOATsize() << "\n";
    cout << "bool: " << getBOOLsize() << "\n";
    TimeStop();
    drawquad();
    TimeStop();
    clear();
    cin.get();
    return 0;
}