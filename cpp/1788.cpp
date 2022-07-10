#include <iostream>
#define MOD 1000000000
using namespace std;

int fib[2000001]; // -1000000~1000000 이므로 i-1000000번째 피보나치 수

int idx(int x){
    return x+1000000;
}

int main(void){
    int n;
    cin>>n;
    fib[idx(0)] = 0;
    fib[idx(1)] = 1;
    for (int i=2 ; i<=1000000 ; i++){
        fib[idx(i)] = (fib[idx(i-1)] + fib[idx(i-2)])%MOD;
    }
    // f(n) = f(n-1) + f(n-2) 에 n=n+2 대입
    // f(n) = f(n+2) - f(n+1)
    for (int i=-1 ; i>=-1000000 ; i--){
        fib[idx(i)] = (fib[idx(i+2)] - fib[idx(i+1)])%MOD;
    }
    if (fib[idx(n)]>0){
        cout<<"1\n"<<fib[idx(n)];
    }
    else if (fib[idx(n)]<0){
        cout<<"-1\n"<<-fib[idx(n)];
    }
    else {
        cout<<"0\n0";
    }
    return 0;
}