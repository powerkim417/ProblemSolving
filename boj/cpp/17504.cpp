#include <iostream>

using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

long long int gcd(long long int a, long long int b){
    if (a<b) {
        long long int temp = a;
        a = b;
        b = temp;
    }
    // now a>=b
    while (1){
        long long int g = a%b;
        if (g==0) break;
        a = b;
        b = g;
    }
    return b;
}

int main(void){
    int n;
    cin>>n;
    long long int a[n];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    long long int bj = 1;
    long long int bm = a[n-1];
    for (int i=n-2 ; i>=0 ; i--){
        bj += a[i]*bm;
        swap(bj, bm);
    }
    bj = bm - bj;
    long long int g = gcd(bm, bj);
    cout<<bj/g<<" "<<bm/g;
}