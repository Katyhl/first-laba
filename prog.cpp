#include <iostream>
using namespace std;
int main() {
    setlocale(0, "");
    //first

    cout << "для int отводится:" << sizeof(int) << "байт" << "\n";
    cout << "для short int отводится: " << sizeof(short int) << " байт" << "\n";
    cout << "для long int отводится: " << sizeof(long int) << " байт" << "\n";
    cout << "для float отводится: " << sizeof(float) << " байт" << "\n";
    cout << "для double отводится: " << sizeof(double) << " байт" << "\n";
    cout << "для long double отводится: " << sizeof(long double) << " байт" << "\n";
    cout << "для char отводится: " << sizeof(char) << " байт" << "\n";
    cout << "для bool отводится: " << sizeof(bool) << " байт" << "\n";
    cout << "\n";
    cout << "\n";


    //second
    cout << "Введите целое число: ";
    int number, i;
    cin >> number;
    cout << "двоичное представление в памяти int:" << endl;
    unsigned int mask = 1 << sizeof(int)*8 - 1;
    for (int i = 0; i <= (sizeof(int)*8 - 1); i++) {
        if (number & mask) {
            cout << "1";
        }
        else { 
            cout << "0";
        }
        if (i == 1 || i % 8 == 0) {
            cout << "  ";
        }
        mask >>= 1;
    }
    cout << "\n";
    cout << "\n";




    //third
    union 
    {
        float realnumber;
        int anothernumber;

    };
    cout << "Введите вещественное число: ";
    cin >> realnumber;
    cout << "двоичное представление в памяти float:" << endl;
    unsigned int maskk  = 1 << sizeof(float)*8 - 1;
    for (int i = 0; i <= (sizeof(float)*8-1); ++i) {
        if (anothernumber & maskk) {
            cout << "1";
        }
        else { 
            cout << "0";
        }
        if (i == 1 || i % 8 == 0) {
            cout << "  ";
        }
        maskk >>= 1;

    }

    cout << endl;



    //fourth
    cout << "Введите число типа double: ";
    union {
        double numberdouble;
        unsigned int double_divided_on_two_parts[2];
    };
    cin >> numberdouble;
    cout << "двоичное представление в памяти double: "<< endl;
    unsigned int maskd = 1 << ((sizeof(int) * 8) - 1);
    for (int i = 1; i >= 0; --i) {
        for (int j = 0; j <= (sizeof(int) * 8 - 1); ++j) {
            putchar(double_divided_on_two_parts[i] & maskd ? '1' : '0');
            maskd >>= 1;
            if (i == 1 & (j == 0 || j == 11)) {
                putchar(' ');
            };
        };
        maskd = 1 << ((sizeof(int) * 8) - 1);

    };
    return 0;
}