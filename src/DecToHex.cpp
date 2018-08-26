// 
// Created by zengtong on 2018/8/26 8:50 AM.
//

#include <string>
#include <iostream>

using namespace std;

class Convert {
public:
    string DecToHex(int n) {
        auto num = static_cast<unsigned int>(n); // if n is negative number, then using two's component method. -1 > 0xffffffff
        if (num == 0) return "0x0";
        string output;
        while (num) {
            int current = num % 16;
            output.push_back(hex[current]);
            num /= 16;
        }
        return "0x" + string(output.rbegin(), output.rend());
    }

private:
    const string hex = "0123456789abcdef";
};

int main() {
    int num;
    while (cin >> num) {
        cout << Convert().DecToHex(num) << endl;
    }
    return 0;
}