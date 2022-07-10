#include <iostream>

using namespace std;

int bunmo(int n){ // 한자리면 10, 두자리면 100, 세자리면 1000 반환
    int ret = 1;
    while (n>0){
        n /= 10;
        ret *= 10;
    }
    return ret;
}

int main(void){
    int t, n;
    cin>>t;
    while (t--){
        cin>>n;
        if ((n*n) % bunmo(n) == n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}