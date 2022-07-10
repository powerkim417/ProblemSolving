#include <iostream>

using namespace std;

int n, k;
bool able[401][401] = {};

// 플로이드 와샬로 모든 방문가능 여부(TF) 계산 가능

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int a,b;
    for (int i=0 ; i<k ; i++){
        cin>>a>>b;
        able[a][b] = true;
    }
    for (int k=1 ; k<=n ; k++){
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                if (able[i][k] && able[k][j]) able[i][j] = true;
            }
        }
    }
    int s;
    cin>>s;
    for (int i=0 ; i<s ; i++){
        cin>>a>>b;
        if (able[a][b]) cout<<"-1\n";
        else if (able[b][a]) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}