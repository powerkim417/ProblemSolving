#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> adj[1001];
bool visited[1001] = {};
queue<int> q;

void dfs(int cur){
    visited[cur] = true;
    cout<<cur<<" ";
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next);
    }
}

void bfs(){
    q.push(v);
    visited[v] = true;
    cout<<v<<" ";
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int next: adj[cur]){
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cout<<next<<" ";
            }
        }
    }
}

int main(void){
    cin>>n>>m>>v;
    int a, b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1 ; i<=n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    cout<<"\n";
    for (int i=1 ; i<=n ; i++){
        visited[i] = false;
    }
    bfs();
}