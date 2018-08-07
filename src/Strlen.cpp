// 
// Created by zengtong on 2018/8/6 9:51 PM.
//

#include <iostream>
using  namespace std;

int Strlen(const char* str) {
    if (str == NULL || *str == '\0') return 0;
    else return Strlen(str + 1) + 1;
}

int main() {
    char* str;
    cout << "strlen(str) = " << Strlen(str) << endl;
    return 0;
}