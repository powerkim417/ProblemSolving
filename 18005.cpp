#include <iostream>

using namespace std;

/*
n=1: 둘다
n=2: 홀
n=3: 둘다
n=4: 짝
n=5: 둘다
n=6: 홀

n=2k+1: 둘다(0)
n=4k+2: 홀(1)
n=4k: 짝(2)
*/
int main(void){
    int n;
    cin>>n;
    if (n%2==1) cout<<"0";
    else if (n%4==2) cout<<"1";
    else cout<<"2";
    return 0;
}