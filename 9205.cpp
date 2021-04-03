#include <iostream>
#define INF (32767+32768)*2+1

using namespace std;

typedef pair<int, int> P;

int abs(int x){
    return (x>0)?x:-x;
}

int l1(P a, P b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

P place[102];
// 출발지(0), 각 편의점(1~n), 도착지(n+1)
bool able[102][102];

int t, n;
int main(void){
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=0 ; i<n+2 ; i++){
            cin>>place[i].first>>place[i].second;
        }
        for (int i=0 ; i<n+2 ; i++){
            for (int j=0 ; j<n+2 ; j++){
                able[i][j] = (l1(place[i], place[j])<=1000) ? true : false;
            }
        }
        // 1000 이하인 경우 true, 아니면 false
        for (int i=0 ; i<n+2 ; i++){
            for (int j=0 ; j<n+2 ; j++){
                for (int k=0 ; k<n+2 ; k++){
                    if (able[i][k] && able[k][j]){
                        able[i][j] = true;
                    }
                }
            }
        }
        // for (int i=0 ; i<n+2 ; i++){
        //     for (int j=0 ; j<n+2 ; j++){
        //         cout<<able[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (!able[0][n+1]) cout<<"sad\n";
        else cout<<"happy\n";
    }    
}