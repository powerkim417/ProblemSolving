#include <iostream>

using namespace std;

int min(int a, int b){
    return (a>b)?b:a;
}

int main(void){
    int n, m;
    cin>>n>>m;
    cout<<min(n,m)/2;
    return 0;
}