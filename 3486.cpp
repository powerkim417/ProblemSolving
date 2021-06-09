#include <iostream>

using namespace std;

int rev(int num){
    int ret = 0;
    while (num>0){
        ret *= 10;
        ret += num%10;
        num /= 10;
    }
    return ret;
}

int main(void){
    int t;
    cin>>t;
    int a, b;
    for (int i=0 ; i<t ; i++){
        cin>>a>>b;
        cout<<rev(rev(a)+rev(b))<<"\n";
    }
    return 0;
}