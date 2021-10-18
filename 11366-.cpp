#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,temp;
    while (cin>>a>>b>>c){
        if (n<0) continue;
        if (a==0 && b==0 && n==0) break;
        for (int i=0 ; i<c ; i++){
            temp = a;
            a = b;
            b = a+temp;
        }
        cout<<b<<"\n";
    }
    return 0;
}