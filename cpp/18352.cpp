#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x, a, b;
vector<int> adj[300001];
int dist[300001] = {};

void bfs(int start){
    for (int i=1 ; i<=n ; i++){
        dist[i] = -1; // unvisited
    }
    queue<pair<int, int>> q; // 노드번호, 거리
    q.push({start, 0});
    dist[start] = 0;
    while (!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for (int next: adj[cur.first]){
            if (dist[next]==-1){
                dist[next] = cur.second+1;
                q.push({next, cur.second+1});
            }
        }
    }
    return;
}

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k>>x;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> answer;

    bfs(x);

    for (int i=1 ; i<=n ; i++){
        if (dist[i]==k) answer.push_back(i); // 자동으로 정렬된 효과를 얻을 수 있음
    }

    if (answer.size()==0) cout<<"-1";
    else {
        for (int a: answer){
            cout<<a<<"\n";
        }
    }
    return 0;
}