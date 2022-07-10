#include <iostream>
#include <queue> // priority_queue
#include <vector>
#include <utility> // pair
#include <functional> // greater

#define INF 798*1000*3 + 1
using namespace std;

typedef pair<int, int> P; // 거리, 노드

int N, E;
int a,b,c;
int X, Y; // 반드시 지나야 하는 두 서로 다른 정점
vector<P> adj[801];
int dist[801][801];

int min(int a, int b){
    return (a>b)?b:a;
}

// 구하는 값은 1 -> X(Y) -> Y(X) -> N 을 지나는 거리 중 최단거리.
// 그러면 다익스트라를 1, X, Y 기준으로 3번 해서
// dist[1][X]+dist[X][Y]+dist[Y][N] 과 dist[1][Y]+dist[Y][X]+dist[X][N] 를 비교해서 작은 값을 내면 되겠다.

void dijkstra(int start){
    for (int i=1 ; i<=N ; i++) dist[start][i] = INF; // 어차피 dijkstra(start) 에서는 dist[start]만 쓰므로 다른 시작점 기준 dist와는 독립. 즉 여기서 해도 된다.
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start][start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();

        if (cur.first > dist[start][cur.second]) continue;

        for (P next: adj[cur.second]){
            if (dist[start][cur.second] + next.first < dist[start][next.second]){
                dist[start][next.second] = dist[start][cur.second] + next.first;
                pq.push({dist[start][next.second], next.second});
            }
        }
    }
}

int main(void){
    cin>>N>>E;
    for (int i=0 ; i<E ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin>>X>>Y;
    // for (int i=1 ; i<=N ; i++){
    //     for (int j=1 ; j<=N ; j++){
    //         dist[i][j] = INF;
    //     }
    // }
    dijkstra(1);
    dijkstra(X);
    dijkstra(Y);
    
    int answer = min(dist[1][X]+dist[X][Y]+dist[Y][N], dist[1][Y]+dist[Y][X]+dist[X][N]);
    // for (int i=1 ; i<=N ; i++){
    //     for (int j=1 ; j<=N ; j++){
    //         cout<<dist[i][j];
    //     }
    //     cout<<"\n";
    // }
    if (answer >= INF) cout<<"-1";
    else cout<<answer;
    
    return 0;
}