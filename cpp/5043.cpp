#include <iostream>

using namespace std;

int main(void){
    long long n;
    int b;
    cin>>n>>b;
    // 0비트: "" 1개
    // 1비트: "", 0, 1 3개
    // 2비트: "", 0, 1, 00, 01, 10, 11 7개
    // 3비트: "", 0, 1, 00, 01, 10, 11,
    // 000, ~ , 111 15개
    // b비트: f(b-1) + 2^b
    long long bn = 1;
    long long twopower = 1;
    for (int i=1 ; i<=b ; i++){
        twopower *= 2;
        bn += twopower;
    }
    if (bn >= n) cout<<"yes";
    else cout<<"no";
    return 0;
}