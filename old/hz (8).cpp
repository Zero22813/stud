#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    cout << "Массивы: \n\n";

    const int size = 10;

    cout << "int\n";
    int intArr[size] = {
        1,2,3,4,5,6,7,8,9,10
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << intArr[i] << "\n";
    }

    cout << "\n";
    cout << "float\n";
    float floatArr[size] = {
        1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << floatArr[i] << "\n";
    }

    cout << "\n";
    cout << "double\n";
    double doubleArr[size] = {
        10.1,20.2,30.3,40.4,50.5,60.6,70.7,80.8,90.9,100.10
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << doubleArr[i] << "\n";
    }

    cout << "\n";
    cout << "short\n";
    short shortArr[size] = {
        1,2,3,4,5,6,7,8,9,10
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << shortArr[i] << "\n";
    }

    cout << "\n";
    cout << "long\n";
    long longArr[size] = {
        100,200,300,400,500,600,700,800,900,1000
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << longArr[i] << "\n";
    }

    cout << "\n";
    cout << "char\n";
    char charArr[size] = {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << charArr[i] << "\n";
    }

    cout << "\n";
    cout << "string\n";
    string stringArr[size] = {
      "Alek",
	  "Kalek",
	  "Valek",
	  "Ratlek",
	  "Tralek",
	  "Rotalek",
	  "Optimalek",
	  "Rasdvoialek",
	  "Operaciolek",
	  "Kompukterlek"
    };

    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << stringArr[i] << "\n";
    }

    cout << "\n";
    cout << "bool\n";
    bool boolArr[size] = {
        true, false, true, false, true, false, true, false, true, false
    };

    for (int i = 0; i < size; i++) {
        if (boolArr[i]) {
            cout << i + 1 << " - true" << "\n";
        }
        else {
            cout << i + 1 << " - false" << "\n";
        }
    }

    return 0;
}