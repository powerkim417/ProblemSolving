#include <iostream>
#include <vector>
#include <queue>
#define INF 499*10000 + 1

using namespace std;

vector<pair<int, int>> adj[501]; // 거리, 인접점
int dist[501][501]; // 출발점이 i일 때, j까지의 최단거리
bool visited[501] = {}; // 벨만 포드를 모든 출발점에서 돌리지 않고 한 컴포넌트에서는 한번만 돌아가도록..!
bool marked[501] = {};

// 벨만 포드 알고리즘
/*
1. 최단경로는 사이클이 들어가지 않으므로 최대 V-1개의 간선만이 들어감
따라서 V-1번의 반복문만 돌리면 최소.
2. 그런데 음의 사이클이 존재한다면, V-1번의 반복 이후 한번 더 돌렸을 경우에 최단거리가 갱신되어 버린다.
따라서, 한번 더 반복하여 V번째 반복을 할 때 갱신이 일어난다면 음의 사이클이 있는 것!
*/

// 음의 사이클이 있는지 찾는 문제
// 음의 사이클이 존재하면, 그 사이클 이후의 모든 정점까지의 최단거리가 -INF 가 되어 버린다.

// 벨만포드에서 간선들을 큐로 저장해서 탐색하는 버전의 코드
// 여기에서 큐에 들어갈 때 큐에 "이미 들어있는" 노드를 마크해서 중복으로 안들어가도록 하면 SPFA 알고리즘이 된다고 한다.

int main(void){
    int TC;
    cin>>TC;
    int N, M, W;
    int s, e, t;
    queue<int> q;
    for (int tc=0 ; tc<TC ; tc++){
        cin>>N>>M>>W;
        bool cycle = false;
        // q = queue<pair<int, int>>();
        // while (!q.empty()) q.pop();
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
            if (visited[start]) continue; // 이걸 안해주면 시간초과가 뜨더라
            visited[start] = true;
            q = queue<int>();
            q.push(start);
            marked[start] = true;
            // 간선을 큐에 저장해서 BFS와 유사한 형태로 돌림
            for (int i=1 ; i<=N ; i++){ // (N-1)+1번 돌림
                int q_size = q.size();
                while (q_size--){ // 한 step동안 큐에 중복으로 들어가지 않도록. 다른 스텝에서는 이미 들어갔었던 큐가 또 들어가도 되는듯
                    int cur = q.front();
                    q.pop();
                    marked[cur] = false; // 큐에서 나왔으므로 false
                    // if (dist[start][cur] == INF) continue; // <- cur가 연결된 next로서 큐에 들어가므로 이럴 일은 없음
                    visited[cur] = true;
                    for (auto next: adj[cur]){
                        if (dist[start][next.second] > dist[start][cur] + next.first){
                            dist[start][next.second] = dist[start][cur] + next.first;
                            if (!marked[next.second]){
                                marked[next.second] = true;
                                q.push(next.second); // 최단거리를 구하는 게 목적이므로 최단거리와 관련없는 노드는 굳이 볼 필요 없음
                            }
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