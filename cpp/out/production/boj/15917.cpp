#include <iostream>

using namespace std;

/* 
a=2^i 꼴인 경우
     a = 0..010..0
    -a = 1..110..0

a&(-a) = 0..010..0 = a
이 성질을 이용한다.
*/

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    for (int i=0 ; i<q ; i++){
        int a;
        cin>>a;
        if ((a&(-a)) == a) cout<<"1\n";
        else cout<<"0\n";
    }
}