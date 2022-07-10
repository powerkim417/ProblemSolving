#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#define INF 9999*1000 + 1

using namespace std;

typedef pair<int, int> P; // cost, next

vector<P> adj[10001];
int dist[10001];
int n, d, c, a, b, s;

void dijkstra(int start){
    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i=1 ; i<=n ; i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();

        if (cur.first > dist[cur.second]) continue;

        for (P next: adj[cur.second]){
            if (dist[cur.second] + next.first < dist[next.second]){
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n>>d>>c;
        for (int i=1 ; i<=n ; i++){
            adj[i].clear();
        }
        for (int i=0 ; i<d ; i++){
            cin>>a>>b>>s;
            adj[b].push_back({s, a});
        }
        dijkstra(c);
        int time = -1;
        int cnt = 0;
        for (int i=1 ; i<=n ; i++){
            if (dist[i]!=INF){
                cnt++;
                if (dist[i]>time) time = dist[i];
            }
        }
        cout<<cnt<<" "<<time<<"\n";
    }
}