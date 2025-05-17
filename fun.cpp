# hw5
//1
#include <iostream>
#include <windows.h>
using namespace std;

void DrawLine(int length, char symbol, int x, int y, bool isHorizontal, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
    if (isHorizontal) {
        for (int i = 0; i < length; i++) {
            cout << symbol;
        }
    }
    else {
        for (int i = 0; i < length; i++) {
            SetConsoleCursorPosition(hConsole, { (short)x, (short)(y + i) });
            cout << symbol;
        }
    }
}

int main() {
    DrawLine(10, '*', 5, 5, true, 12);
    DrawLine(5, '|', 15, 5, false, 12);
    return 0;
}

//2

#include <iostream>
#include <windows.h>
using namespace std;

void Rectangle(int width, int height, char borderSymbol, char fillSymbol, int borderColor, int fillColor, int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < height; i++) {
        COORD pos = { (short)x, (short)(y + i) };
        SetConsoleCursorPosition(hConsole, pos);
        for (int j = 0; j < width; j++) {
            if (i == 0 || i  == height - 1 || j == 0 || j == width - 1) {
                SetConsoleTextAttribute(hConsole, borderColor);
                cout << borderSymbol;
            }
            else {
                SetConsoleTextAttribute(hConsole, fillColor);
                cout << fillSymbol;
            }
        }
    }
}

int main() {
    Rectangle(10, 5, '#', '.', 10, 14, 2, 2);
    return 0;
}

//3

#include <iostream>
using namespace std;

double Cube(double number) {
    return number * number * number;
}

int main() {
    cout << Cube(3) << endl;
    return 0;
}

//4

#include <iostream>
using namespace std;

bool IsPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int main() {
    cout << (IsPrime(17) ? "Yes" : "No") << endl;
    cout << (IsPrime(15) ? "Yes" : "No") << endl;
    return 0;
}
