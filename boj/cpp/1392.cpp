#include <iostream>

using namespace std;

int cur[10001];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    int len, idx=0;
    for (int i=1 ; i<=n ; i++){
        cin>>len;
        while (len--) cur[idx++] = i;
    }
    int query;
    for (int i=0 ; i<q ; i++){
        cin>>query;
        cout<<cur[query]<<"\n";
    }
    return 0;
}