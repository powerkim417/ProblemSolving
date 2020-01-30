#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool visited[1001] = {};

void dfs(int cur){
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next);
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    for (int i=0 ; i<m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int comp = 0;
    for (int i=1 ; i<=n ; i++){
        if (!visited[i]){
            comp++;
            dfs(i);
        }
    }
    cout<<comp;
}