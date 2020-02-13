#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=-1, m=-1;
    while (n!=0 && m!=0){
        cin>>n>>m;
        int src[n], dst[n], s[n], dur[n], e[n];
        for (int i=0 ; i<n ; i++){
            cin>>src[i]>>dst[i]>>s[i]>>dur[i];
            e[i] = s[i] + dur[i];
        }
        int S, D, E; // 경찰이 도청하려고 하는 구간의 정보
        int cnt;
        for (int i=0 ; i<m ; i++){
            cin>>S>>D;
            E = S+D;
            cnt = n;
            for (int j=0 ; j<n ; j++){
                if (e[j]<=S || E<=s[j]) cnt--;
            }
            cout<<cnt<<"\n";
        }
    }
}