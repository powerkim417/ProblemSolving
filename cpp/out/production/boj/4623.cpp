#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(void){
    int a,b,c,d;
    while (cin>>a>>b>>c>>d){
        if (a==0 && b==0 && c==0 && d==0) break;
        if (a>b) swap(a, b);
        if (c>d) swap(c, d);
        double r1 = (double)c/a * 100, r2 = (double)d/b * 100;
        if (r1 >= 100 && r2 >= 100) cout<<"100%\n";
        else cout<<(int)((r1>r2)?r2:r1)<<"%\n";
    }
    return 0;
}