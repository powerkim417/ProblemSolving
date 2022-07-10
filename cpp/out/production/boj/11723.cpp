#include <iostream>

using namespace std;

int bit = 0; // 2^19 ~ 2^0

// 비트마스킹 풀이
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    string cmd;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            x--;
            bit |= (1 << x);
        }
        if (cmd == "remove") {
            cin >> x;
            x--;
            bit &= ~(1 << x);
        }
        if (cmd == "check") {
            cin >> x;
            x--;
            cout << (bool)(bit & (1 << x)) << "\n";
        }
        if (cmd == "toggle") {
            cin >> x;
            x--;
            bit ^= (1 << x);
        }
        if (cmd == "all") {
            bit = (1 << 20) - 1;
        }
        if (cmd == "empty") {
            bit = 0;
        }
        // cout << "current bit: " << bit << "\n";
    }
    return 0;
}