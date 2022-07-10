#include <iostream>
#include <vector>
#define INF 499*10000 + 1

using namespace std;

vector<pair<int, int>> adj[501]; // 거리, 인접점
int dist[501][501]; // 출발점이 i일 때, j까지의 최단거리
bool visited[501] = {}; // 벨만 포드를 모든 출발점에서 돌리지 않고 한 컴포넌트에서는 한번만 돌아가도록..!

// 벨만 포드 알고리즘
/*
1. 최단경로는 사이클이 들어가지 않으므로 최대 V-1개의 간선만이 들어감
따라서 V-1번의 반복문만 돌리면 최소.
2. 그런데 음의 사이클이 존재한다면, V-1번의 반복 이후 한번 더 돌렸을 경우에 최단거리가 갱신되어 버린다.
따라서, 한번 더 반복하여 V번째 반복을 할 때 갱신이 일어난다면 음의 사이클이 있는 것!
*/

// 음의 사이클이 있는지 찾는 문제
// 음의 사이클이 존재하면, 그 사이클 이후의 모든 정점까지의 최단거리가 -INF 가 되어 버린다.

int main(void){
    int TC;
    cin>>TC;
    int N, M, W;
    int s, e, t;
    for (int tc=0 ; tc<TC ; tc++){
        cin>>N>>M>>W;
        bool cycle = false;
        for (int i=1 ; i<=N ; i++){
            visited[i] = false;
            adj[i].clear();
            for (int j=1 ; j<=N ; j++){
                dist[i][j] = INF;
                if (i==j) dist[i][j] = 0;
            }
        }
        for (int i=0 ; i<M ; i++){
            cin>>s>>e>>t;
            adj[s].push_back({t, e});
            adj[e].push_back({t, s});
        }
        for (int i=0 ; i<W ; i++){
            cin>>s>>e>>t;
            adj[s].push_back({-t, e});
        }
        for (int start=1 ; start<=N ; start++){ // 출발점
            if (visited[start]) continue;
            visited[start] = true;
            for (int i=1 ; i<=N ; i++){ // (N-1)번(최단거리 갱신) + 1번(음수사이클 검증)
                // i=1~N-1 까지는 각각 시작점으로부터 i개의 간선을 사용했을 때로 최단거리 갱신 시도.
                // i=1일 때는 dist[cur][next]들이 각 cur에서 1개 간선만 뻗은 값을 통해 갱신되는거라면
                // i=k일 때는 이전까지 dist[cur] 배열이 (k-1)개 간선만 사용했을 때를 통해 갱신되었다고 생각하고
                // dist[next](k개 간선 사용 기준)를 dist[cur](k-1개 간선 사용 기준)와 <cur, edge>간선 비용을 통해 갱신 시도하는 것.

                // 헷갈릴 수도 있는 포인트: 
                // 시작점에서 cur가 연결되어 있지 않은 경우 i=0일 때 하나의 간선으로 닿지 못하므로
                // dist[cur] 또한 INF로 유지되어 있어 갱신되지 않음.
                for (int cur=1 ; cur<=N ; cur++){ // dist[start][cur]를 사용하여 dist[start][next] 갱신 시도
                    if (dist[start][cur] == INF) continue; // 아직 cur가 연결되어있지 않은 경우
                    visited[cur] = true;
                    for (auto next: adj[cur]){
                        if (dist[start][next.second] > dist[start][cur] + next.first){
                            dist[start][next.second] = dist[start][cur] + next.first;
                            if (i==N) cycle = true;
                        }
                    }
                }
            }
            if (cycle) break; // N번 돌아서 사이클 발견했으면 다른 출발점 볼 필요 없음
        }
        cout<<((cycle)?"YES\n":"NO\n");
    }
}