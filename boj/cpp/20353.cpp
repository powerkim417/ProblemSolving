// boj.kr/16600 과 똑같은 내용의 문제라 같은 코드
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long long a;
    cin>>a;
    cout<<fixed;
    cout.precision(6);
    cout<<4*sqrt(a);
    return 0;
}