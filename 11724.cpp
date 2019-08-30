#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1001];
vector<int> adj[1001];

void dfs(int x){
    visited[x] = true;
    for (int next: adj[x]){
        if (!visited[next]) dfs(next);
    }
}

int main(void){
    int n,m;
    cin>>n>>m;
    int u,v;
    for (int i=0 ; i<m ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int comp = 0;
    for (int i=1 ; i<=n ; i++){
        /* 모든 점에 대해 dfs를 실시하되,
        이미 방문을 한 점들은 제외한다.
        그러면 첫번째 dfs에서 지나간 점들이 모두 제외되고,
        이들은 1번째 component의 요소들이 되는 것.
        만약 이 포문에서 방문하지 않은 점이 나온다면
        그 점은 새로운 component의 첫 dfs 방문점이 되고,
        그 점을 기준으로 연결된 모든 점을 다 방문한다.
        그 점들은 2번째 component의 요소들이 된다. 
        */
        if (!visited[i]){
            dfs(i);
            comp++;
        }
    }
    cout<<comp;
}