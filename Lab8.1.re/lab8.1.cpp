#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція підрахунку
int Count(char* str, int i) {
    if (strlen(str) < 3)
        return 0;
    if (str[i + 2] != 0) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    return 0;
}

// Функція заміни "abc" на "****" 
char* Change(char* dest, const char* str, char* t, int i) {
    if (str[i + 2] != 0) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            strcat(t, "****"); //  "****" замість "abc"
            return Change(dest, str, t + 4, i + 3); // провіряєм знов через 3 символи
        }
        else {
            *t++ = str[i++]; //копіюєм
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of 'abc'" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}