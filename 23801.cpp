#include <iostream>
#include <vector>
#include <queue>
#define INF 99999000001

using namespace std;

typedef pair<double, int> P;
vector<P> adj[100001];
long long dist[2][100001]; // x, z
int n, m, u, v, w, x, z, p, y;

void dijkstra(bool isZ){
    for (int i=1 ; i<=n ; i++) dist[isZ][i] = INF;
    int start = (isZ) ? z : x;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, start});
    dist[isZ][start] = 0;
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();
        if (cur.first > dist[isZ][cur.second]) continue;
        for (P next: adj[cur.second]){
            if (dist[isZ][next.second] > dist[isZ][cur.second] + next.first){
                dist[isZ][next.second] = dist[isZ][cur.second] + next.first;
                pq.push({dist[isZ][next.second], next.second});
            }
        }
    }
}

// X, Z에 대해 다익스트라 실시 후
// dist(x-y) + dist(y-z)(양방향 그래프이므로) 중 최소값을 찾으면 됨
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0 ; i<m ; i++){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    cin>>x>>z;
    cin>>p;
    long long answer = 2*INF+1;
    dijkstra(false);
    dijkstra(true);
    for (int i=0 ; i<p ; i++){
        cin>>y;
        if (dist[0][y]+dist[1][y] < answer){
            answer = dist[0][y]+dist[1][y];
        }
    }
    if (answer >= INF) cout<<"-1";
    else cout<<answer;
    // cout<<"\n";
    // for (int i=0 ; i<2 ; i++){
    //     for (int j=1 ; j<=n ; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}