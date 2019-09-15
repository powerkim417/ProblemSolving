#include <iostream>

using namespace std;

int main(void){
    int a,b,c;
    // 1101
    //   11
    // 1110
    cin>>a>>b>>c;
    for (int i=0 ; i<c ; i++){
        a = a ^ b;
    }
    cout<<a;
}