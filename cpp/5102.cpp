#include <iostream>

using namespace std;

int main(void){
    int a, b;
    while (cin>>a>>b){
        if (a==0 && b==0) break;
        if ((a-b)%2==0) cout<<(a-b)/2<<" 0\n";
        else if (a-b==1) cout<<"0 0\n";
        else cout<<(a-b-3)/2<<" 1\n";
    }
    return 0;
}