#include <iostream>

using namespace std;

int main(void){
    long long p1,q1,p2,q2;
    cin>>p1>>q1>>p2>>q2;
    // p1/q1 * p2/q2 / 2 가 정수인지 확인
    long long p = p1*p2;
    long long q = 2*q1*q2;
    if (p%q == 0) cout<<"1";
    else cout<<"0";
    return 0;
}