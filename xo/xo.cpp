#include <iostream>
#include <string>

using namespace std;

void Mysetlocale();
void clear();

int main(){

    return 0;
}

void Mysetlocale(){
    system("chcp 65001");
    system("cls");
}

void clear(){
    system("cls");
}