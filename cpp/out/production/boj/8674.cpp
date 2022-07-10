#include <iostream>

using namespace std;

long long min(long long a, long long b){
    return (a>b)?b:a;
}

int main(void){
    long long a, b;
    cin>>a>>b;
    if (a%2==0 || b%2==0) cout<<"0";
    else {
        cout<<min(a,b);
    }
    return 0;
}