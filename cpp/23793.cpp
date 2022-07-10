#include <iostream>
#include <queue>
#include <vector>
#define INF 99999*10000+1

using namespace std;

typedef pair<int, int> P; // 거리, 도착지

vector<P> adj[100001];

// mid: 다익스트라 시 거치면 안되는 정점
// 거치면 안되는 정점 조건이 없을 경우 겹칠 일 없는 -1를 전달함
// 일반적인 경우 + 거치면 안되는 정점 조건이 있는 경우 둘다 가능하도록 모듈화
int dijkstra(int n, int start, int mid, int end){
    int dist[100001];
    for (int i=1 ; i<=n ; i++) dist[i] = INF;
    priority_queue<P, vector<P>, greater<P>> pq;
    // 현재까지 알고 있는 노드들과 그까지의 현재 기준 최단거리가 저장되어 있음
    // 매 시행마다 pop하는 cur에 대해 dist[cur]이 확정된 상태에서 다른 최단거리들이 갱신됨
    // 첫 시행에는 dist[start]=0 으로 고정인 상태에서 인접 노드들의 dist 갱신
    // 그리고 갱신되는 dist들은 pq에 들어간다.
    // 가장 가까운 인접 노드가 B라고 할 때,
    // 두번째 시행에서는 dist[B]=len(start->B)가 고정임이 보장된 상태에서
        // 고정이 보장되는 이유: len(start->B)가 가장 짧은 거리로 뽑혔는데,
        // dist[B]로 len(start->B)보다 짧은 거리(start->C->B)가 존재한다면
        // 가장 가까운 노드로 B가 아니라 C가 뽑혔어야 함! 그러므로 보장됨
    // 보장된 dist[B]를 기반으로 B의 인접 노드들의 dist를 갱신
    // 이때, 갱신되는 dist를 pq에 넣는다!

    // 실제로 최단거리와 관련이 없는 간선들이 pq에 들어가는 경우에 대해 걱정하지 않아도 됨
    // 이 간선들은 자기 차례에 pop될 때 dist값을 갱신하지 못하므로..

    // 예외처리
    // 연결그래프가 아니거나, 유향그래프에서 특정 정점으로 못갈 때
    pq.push({-1, start});
    dist[start] = 0;
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second]) continue;
        for (P next: adj[cur.second]){
            if (next.second==mid) continue; // y를 거치지 않을 때는 다음 정점을 고를 때 y를 배제
            if (dist[next.second] > dist[cur.second] + next.first){
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
    if (dist[end]==INF) return -1;
    else return dist[end];
}

// 다익스트라 O(ElogV)
// Y를 안거치고 X->Z를 가는 경로를 구하기 위해
// 다익스트라를 V번 하는건 시간초과가 난다.
// 해법
// 1번은 X->Y + Y->Z를 하면 되고,
// 2번은 X->Z를 하되 다음노드 선정 시 Y를 배제하면 됨
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int u, v, w, x, y, z;
    for (int i=0 ; i<m ; i++){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
    }
    cin>>x>>y>>z;
    int x2y = dijkstra(n, x, -1, y);
    int y2z = dijkstra(n, y, -1, z);
    if (x2y == -1 || y2z == -1) cout<<"-1";
    else cout<<(x2y+y2z);
    cout<<" "<<dijkstra(n, x, y, z);
    return 0;
}