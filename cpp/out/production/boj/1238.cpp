#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#define INF 999*100 + 1

using namespace std;

typedef pair<int, int> P; // 거리, 노드번호
int N, M, X;
int a, b;
int T;
vector<P> adj[1001];
int dist[1001][1001];

void dijkstra(int start){
    for (int i=1 ; i<=N ; i++) dist[start][i] = INF;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start][start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();

        if (cur.first > dist[start][cur.second]) continue;

        for (P next: adj[cur.second]){
            if (dist[start][cur.second]+next.first<dist[start][next.second]){
                dist[start][next.second] = dist[start][cur.second]+next.first;
                pq.push({dist[start][next.second], next.second});
            }
        }
    }
}

// dist[student][X] + dist[X][student] 가 가장 큰 학생을 구하는 것이 답.

int main(void){
    cin>>N>>M>>X;
    for (int i=0 ; i<M ; i++){
        cin>>a>>b>>T;
        adj[a].push_back({T, b});
    }
    for (int i=1 ; i<=N ; i++) dijkstra(i);
    int answer = dist[1][X]+dist[X][1];
    // cout<<answer<<"\n";
    for (int i=2 ; i<=N ; i++){
        if (answer < dist[i][X]+dist[X][i]){
            answer = dist[i][X]+dist[X][i];
        }
        // cout<<answer<<"\n";
    }
    cout<<answer;
    return 0;
}