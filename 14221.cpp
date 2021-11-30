#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 4999*10000+1

using namespace std;

typedef pair<int, int> P;

vector<P> adj[5001];
vector<int> home, cvs;
int dist[5001];

int dijkstra(int n, int start){
    for (int i=1 ; i<=n ; i++){
        dist[i] = INF;
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({-1, start});
    dist[start] = 0;
    while (!pq.empty()){
        P cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second]) continue;
        for (P next: adj[cur.second]){
            if (dist[next.second] > dist[cur.second] + next.first){
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
    int ret = INF;
    for (int c: cvs){
        if (ret > dist[c]) ret = dist[c];
    }
    return ret;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int a,b,c;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int p,q; cin>>p>>q;
    int temp;
    for (int i=0 ; i<p ; i++){
        cin>>temp;
        home.push_back(temp);
    }
    sort(home.begin(), home.end());
    for (int i=0 ; i<q ; i++){
        cin>>temp;
        cvs.push_back(temp);
    }
    int min_dist = INF;
    int answer = 1; // 혹시라도 연결 그래프가 아니라 모두 안닿을 때, 모두 INF인 상황에서 가장 정점 번호 낮은 1 출력하도록
    for (int h: home){
        temp = dijkstra(n, h);
        // cout<<h<<" "<<temp<<"\n";
        if (temp < min_dist) {
            min_dist = temp;
            answer = h;
        }
    }
    cout<<answer;
    return 0;
}