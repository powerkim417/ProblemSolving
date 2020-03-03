#include <iostream>
#include <vector>
#include <queue>
#define INF 499*10000+1

using namespace std;

int n, m;
vector<pair<int, int>> adj[501]; // 시간, 노드
queue<int> q;
int dist[501] = {};
bool marked[501] = {}; // 큐에 있는지

// 벨만 포드
// 음수 사이클이 존재하는 경우: 답이 -1
// 음수사이클이 존재하지 않는 경우: 각각 출력하고, 닿지 않으면 그 도시만 -1

int main(void){
    cin>>n>>m;
    int a, b, c;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    for (int i=2 ; i<=n ; i++) dist[i] = INF;
    // 1번 도시가 출발점
    dist[1] = 0;
    q.push(1);
    marked[1] = true;
    bool cycle = false;
    for (int i=1 ; i<=n ; i++){ // (n-1) + 1번의 step
        int q_size = q.size();
        while (q_size--){ // 한 개의 step을 관리
            int cur = q.front();
            q.pop();
            marked[cur] = false;
            for (pair<int, int> next: adj[cur]){
                if (dist[next.second] > dist[cur] + next.first){
                    dist[next.second] = dist[cur] + next.first;
                    if (!marked[next.second]){
                        q.push(next.second);
                        marked[next.second] = true;
                    }
                    if (i==n) cycle = true;
                }
            }
        }
    }
    if (cycle) cout<<"-1";
    else {
        for (int i=2 ; i<=n ; i++){
            if (dist[i] == INF) cout<<"-1\n";
            else cout<<dist[i]<<"\n";
        }
    }
    return 0;
}