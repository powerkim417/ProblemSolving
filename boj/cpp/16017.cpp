#include <iostream>

using namespace std;

int main(void){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    bool flag = true;
    if (a<8) flag = false;
    else if (b!=c) flag = false;
    else if (d<8) flag = false;

    if (flag) cout<<"ignore";
    else cout<<"answer";
    return 0;
}