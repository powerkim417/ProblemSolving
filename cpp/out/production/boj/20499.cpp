#include <iostream>

using namespace std;

int main(void){
    int k,d,a;
    char c;
    cin>>k>>c>>d>>c>>a;
    if (k+a<d || d==0) cout<<"hasu";
    else cout<<"gosu";
    return 0;
}