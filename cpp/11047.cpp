#include <iostream>

using namespace std;

int main(void){
    int n, k;
    cin>>n>>k;
    int coin[n];
    for (int i=0 ; i<n ; i++){
        cin>>coin[i];
    }
    int cnt = 0;
    for (int i=n-1 ; i>=0 ; i--){
        if (k<coin[i]) continue;
        cnt += k/coin[i];
        k = k - (k/coin[i])*coin[i];
    }
    cout<<cnt;
}