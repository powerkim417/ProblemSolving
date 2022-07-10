#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

using namespace std;

typedef pair<int, int> P; 
// first: 거리 weight
// second: (한 정점과 이어지는)점
// 비교 시 first부터 비교

const int INF = 199991;

int main(void){
    int V,E;
    cin>>V>>E;
    vector<P> adj[V+1];
    int dist[V+1];
    for (int i=0 ; i<V+1 ; i++){
        dist[i] = INF;
        // memset은 1바이트 단위로만 들어가지므로
        // 200000 으로 초기화할 수는 없음
    }
    // visited의 경우 필요 없다!
    // 거리가 inf 인 경우 방문하지 않았으므로
    // 그렇게 확인하면 됨
    priority_queue<P, vector<P>, greater<P>> pq;
    int k;
    cin>>k;
    int u,v,w;
    for (int i=0 ; i<E ; i++){
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
    }
    pq.push({0, k});
    // 다익스트라 알고리즘 메인
    while (!pq.empty()){
        // 특정 점 기준. cur_dist는 시작점-특정점 간 임시 최단거리
        int cur_dist = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (cur_dist > dist[pos]) // 한번에 가는 거리가 더 긴 경우 버림
            continue; 

        dist[pos] = cur_dist;
        
        for (P next: adj[pos]){
            if (cur_dist + next.first < dist[next.second]){
                pq.push({cur_dist + next.first, next.second});
                dist[next.second] = cur_dist + next.first;
            }
        }
    }
    for (int i=1 ; i<=V ; i++){
        if (dist[i] == INF) cout<<"INF";
        else cout<<dist[i];
        cout<<"\n";
    }
    return 0;
}