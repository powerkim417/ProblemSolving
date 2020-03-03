#include <iostream>
#include <queue>
#include <vector>
#define INF 10*19999 + 1

using namespace std;

int V, E, K;
typedef pair<int, int> P; // 간선 가중치(보조값), 도착점(메인).
vector<P> adj[20001];
int dist[20001]; // 출발점 K로부터의 거리

void dijkstra(int start){
    for (int i=1 ; i<=V ; i++) dist[i] = INF;
    priority_queue<P, vector<P>, greater<P>> pq; // edge가 저장되는게 아님! {push할 기준 출발노드-해당노드간 최단거리, 해당노드} 가 저장된다고 이해하면 됨
    // 시작점 관련 초기화
    dist[K] = 0;
    pq.push({0, K}); // 현재 ->K 까지 0의 비용을 소모
    while (!pq.empty()){
        // pq에 들어있는 점 중 현재까지 추정 dist가 가장 짧은 값이 cur가 된다.
        P cur = pq.top();
        pq.pop();

        if (cur.first > dist[cur.second]) continue; // 탐색하려 했는데 지금까지 구한 최단거리보다 비용이 큰 간선인 경우는 거른다.
        
        // cur.second의 최단거리는 확정된 상태!
        // Why? 이 시점에서 cur.second보다 짧은 거리가 있었다면 pq에 의해 더 짧은 간선들을 통해 계산되었을 것. 
       
        // {push할 기준 출발노드-해당노드간 최단거리, 해당노드} 후보로 받아온 것에 대한 검증. 이로 인해 최단거리가 갱신된다면 다른 정점에 대한 {push할 기준 출발노드-해당노드간 최단거리, 해당노드} 후보를 또 push한다.
        for (P next: adj[cur.second]){
            // 인접한 노드들의 dist를 갱신하고, pq에 넣음
            if (dist[cur.second] + next.first < dist[next.second]){
            // next로 이미 방문한 곳을 재방문하려 하는 경우? 이미 dist[cur]<=dist[next] 이므로 걸러짐. 
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
                // 시작 노드로부터 갓 방문한 경우 next라는 간선을 그대로 갖다 넣는 것과 같음
                // 해당 간선이 dist[next.second]를 갱신하는 간선인 경우 next.second와 갱신된 비용(첫 방문인 경우 거쳐온 전체 경로)을 pq에 넣으며,
                // 이 간선에 의해 최단경로가 아니게 된 간선은 위의 조건문에 의해 걸러짐.

                // 갱신된 값, 실제로 있지도 않는 간선을 push하는 이유:
                // 특정 정점까지의 최단거리를 갱신하려면 그 이전 노드를 방문해야 하는데,
                // 갱신된 정보를 통해 받아온 next.second가 이 '이전 노드' 역할을 해야 하므로.
                // 넣어만 주면 next.second에 대한 간선 중 가장 비용이 작은 간선이 PQ를 통해 알아서 골라지고, 이를 통해 최단경로가 갱신되고,
                // 이보다 큰 비용의 간선들은 조건문에서 걸러짐
            }
        }
    }
}

int main(void){
    cin>>V>>E>>K;
    int u, v, w;
    for (int i=0 ; i<E ; i++){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});

    }
    dijkstra(K);
    for (int i=1 ; i<=V ; i++){
        if (dist[i] == INF) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}