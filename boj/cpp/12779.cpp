#include <iostream>
#include <cmath>

using namespace std;

long long int gcd(long long int x, long long int y){
    long long int temp;
    if (x<y){
        temp = y;
        y = x;
        x = temp;
    } // x >= y
    while (y != 0){
        temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}

int main(void){
    // N: 약수의 갯수가 홀수 -> 제곱수
    long long int a,b;
    cin>>a>>b;
    long long int cnt = sqrt(b) - ceil(sqrt(a+1)) + 1;
    if (cnt == 0) cout<<"0";
    else cout<<cnt/gcd(cnt,b-a)<<"/"<<(b-a)/gcd(cnt,b-a);
}