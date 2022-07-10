#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b){
    if (a<b) swap(a, b);
    int r;
    while (a%b != 0){
        r = a%b;
        a = b;
        b = r;
        // 이렇게 하면 항상 a>b
    }
    return b;
}

int main(void){
    long long w, h;
    while (cin>>w>>h){
        if (w==0 && h==0) break;
        int g = gcd(w, h);
        long long answer = ((long long)w)*h/((long long)g*g);
        cout<<answer<<"\n";
    }
    return 0;
}