#include <iostream>

using namespace std;

int n, m;
int sum[100001] = {}; // sum[0]은 아무것도 없는 상태
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int temp;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        sum[i] = sum[i-1] + temp;
    }
    // for (int i=1 ; i<=n ; i++){
    //     cout<<sum[i]<<"\n";
    // }
    int i, j;
    while (m--){
        cin>>i>>j;
        cout<<sum[j]-sum[i-1]<<"\n";
    }
    return 0;
}