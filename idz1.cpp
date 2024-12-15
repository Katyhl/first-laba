#include <iostream>
using namespace std;

int idz_int(int number, int position) {
    return number ^ (1 << position); // Инвертировать бит
}

float idz_float(float number, int position) {
    union {
        float f;
        unsigned int i;
    } data;
    data.f = number;
    data.i ^= (1u << position);
    return data.f;
}

double idz_double(double number, int position) {
    union {
        double d;
        unsigned long long i;
    } data;
    data.d = number;
    data.i ^= (1ull << position);
    return data.d;
}
void OutInt(int number) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        cout << ((number >> i) & 1);
    }
    cout << endl;
}

void OutFlo(float number) {
    union {
        float f;
        unsigned int i;
    } data;
    data.f = number;
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i) {
        cout << ((data.i >> i) & 1);
    }
    cout << endl;
}

void OutDouble(double number) {
    union {
        double d;
        unsigned long long i;
    } data;
    data.d = number;
    for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i) {
        cout << ((data.i >> i) & 1);
    }
    cout << endl;
}

void Menu() {
    cout << "Выберите тип данных:\n";
    cout << "1. int" << endl;
    cout << "2. float" << endl;
    cout << "3. double" << endl;
    cout << "Ваш выбор: ";
}

int main() {


    int choice;
    Menu();
    cin >> choice;

    cout << "Введите количество бит для изменения: ";
    int count;
    cin >> count;

    int bitPositions[32]; // Максимум 32 бита для int
    cout << "Введите номера битов (от 0): ";
    for (int i = 0; i < count; ++i) {
        cin >> bitPositions[i];
    }

    switch (choice) {
        case 1: {
            int value;
            cout << "Введите значение int: ";
            cin >> value;
            for (int i = 0; i < count; ++i) {
                value = idz_int(value, bitPositions[i]);
            }
            cout << "Результат (int): " << value << "\n";
            cout << "Побитовое представление: ";
            OutInt(value);
            break;
        }
        case 2: {
            float value;
            cout << "Введите значение float: ";
            cin >> value;
            for (int i = 0; i < count; ++i) {
                value = idz_float(value, bitPositions[i]);
            }
            cout << "Результат (float): " << value << "\n";
            cout << "Побитовое представление: ";
            OutFlo(value);
            break;
        }
        case 3: {
            double value;
            cout << "Введите значение double: ";
            cin >> value;
            for (int i = 0; i < count; ++i) {
                value = idz_double(value, bitPositions[i]);
            }
            cout << "Результат (double): " << value << "\n";
            cout << "Побитовое представление: ";
            OutDouble(value);
            break;
        }

    }

    return 0;
}