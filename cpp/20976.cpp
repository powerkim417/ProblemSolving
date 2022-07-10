#include <iostream>

using namespace std;

int main(void){
    int a, b, c;
    cin>>a>>b>>c;
    if (a>b){
        if (b>c) cout<<b;
        else cout<<((a>c)?c:a);
    }
    else { // b>=a
        if (a>c) cout<<a;
        else cout<<((b>c)?c:b);
    }
    return 0;
}