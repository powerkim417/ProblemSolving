#include <iostream>

using namespace std;

const int INF = 9900001;

// 플로이드 워셜 알고리즘

int main(void){
    int n,m;
    cin>>n>>m;
    int a,b,c;
    int dist[n][n];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (i==j) dist[i][j] = 0; // 제자리는 0
            else dist[i][j] = INF;
        }
    }
    for (int i=0 ; i<m ; i++){
        cin>>a>>b>>c;
        if (c < dist[a-1][b-1]) // 두 정점간 여러 간선일 때 가장 짧은 경로가 들어가야 함
            dist[a-1][b-1] = c;
    }
    // 플로이드 워셜 알고리즘 메인 부분
    for (int k=0 ; k<n ; k++){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // dist[i][j]가 만약 답이라면
                    // dist[i][k]와 dist[k][j] 가 갱신되어있다는게 보장되어있음
                    /* ex) 6-1-8-2-4 인 경우
                    k=1일 때 6-1-8이 dist[6][8]의 최저인게 보장되고
                    k=2일 때 8-2-4가 dist[8][4]의 최저인게 보장되고
                    k=8일 때 6-1- 8 -2-4 가 dist[6][4]의 최저인게 확정된다.

                    (200301 추가)
                    그리고.. dist[i][j]에 대한 갱신 기회는 총 n번(k for문) 있기 때문에..
                    처음에 정답으로 갱신되지 않아도 결국 갱신될 것
                    k번째 정점을 거치는 반복문을 실행할 시점에는
                    0~k-1번째 정점을 거치는 기준까지는 이미 최소값들이 저장된 상태이므로
                    k for문을 하나하나 지나가는 과정이 점점 최소값들로 정예화되는 과정이라 볼 수 있음
                    */
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (dist[i][j] == INF) cout<<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}