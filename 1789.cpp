#include <iostream>

using namespace std;

// 1: 1(1), 2
// 2: 3(1+2), 4, 5
// 3: 6(1+2+3), 7, 8, 9

// 19: 190(1+..+19), .., 200, ...
// 즉, 1+..+k 로 나타낼 수 있는 수부터 n의 값이 1씩 늘어난다.

int main(void){
    long long s, n=1;
    cin>>s;
    while (1){
        if (n*(n+1)/2 > s) break;
        n++;
    }
    n--;
    cout<<n;
    return 0;
}