#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 798*1000*3 + 1

using namespace std;

int n;
typedef pair<int, int> P;
vector<P> adj[801];
int dist[801]; // 1번 정점 기준 최단거리를 구하는데 우선 쓰고, v1번 v2번에 대해서도 행렬을 재활용해서 사용할 예정

void dijkstra(int start){
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});
    for (int i=1 ; i<=n ; i++){
        if (i==start) dist[i] = 0;
        else dist[i] = INF;
    }
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();

        if (cur.first > dist[cur.second]) continue;

        for (P next: adj[cur.second]){
            if (dist[cur.second]+next.first < dist[next.second]){
                dist[next.second] = dist[cur.second]+next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int e, a, b, c, v1, v2;
    cin>>n>>e;
    for (int i=0 ; i<e ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin>>v1>>v2;
    // 1번 정점 -> v1(v2)번 정점 -> v2(v1)번 정점 -> N번 정점으로 이동해야 하므로
    // 각 경로에 대한 최단거리를 합한 두 경로를 비교해서 더 작은 값을 택한다.
    
    int path1 = 0, path2 = 0;
    dijkstra(1);
    path1 += dist[v1];
    path2 += dist[v2];
    dijkstra(v1);
    path1 += dist[v2];
    path2 += dist[n];
    dijkstra(v2);
    path1 += dist[n];
    path2 += dist[v1];

    int answer = (path1>path2)?path2:path1;
    
    if (answer >= INF) cout<<"-1";
    else cout<<answer;
    return 0;
}