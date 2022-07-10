#include <iostream>

using namespace std;

int dist[20][20];
bool rmv[20][20] = {}; // 해당 간선 삭제 여부

// 플로이드 와샬 활용
// 플로이드 와샬인걸 알면 매우 쉬워짐..
// 이미 최단거리가 다 나왔으므로 이에 대해 모든 ik+kj==ij인 경우를 다 살펴보고, 이 경우 ij간선을 필요가 없으므로 지운다.
// 이 작업은 필요없는 간선은 전부 지우고, 필요한 간선은 건드리지 않음

// 주어진 입력이 이미 최단경로로 주어졌는데, 다시 계산해보았을 때 더 최단거리가 있는 경우 -1 출력

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>dist[i][j];
        }
    }
    for (int k=0 ; k<n ; k++){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (dist[i][k]+dist[k][j]==dist[i][j]){ //i==j인 경우는 위의 조건문을 통과하지 못함
                    if (i==k || j==k) continue; // 이 경우는 dist[i][j]==dist[i][j]라는 무조건 참인 경우로 만들어버리므로 예외처리
                    // 이 경우 i-j 간선은 없어도 됨
                    // cout<<"("<<i<<"-"<<k<<")+("<<k<<"-"<<j<<")=("<<i<<"-"<<j<<")\n";
                    rmv[i][j] = true;
                    rmv[j][i] = true;
                }
                else if (dist[i][k]+dist[k][j]<dist[i][j]){
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<n ; j++){
    //         cout<<(rmv[i][j]?0:dist[i][j])<<" ";
    //     }
    //     cout<<"\n";
    // }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            if (!rmv[i][j]) answer += dist[i][j];
        }
    }
    cout<<answer;
    return 0;
}