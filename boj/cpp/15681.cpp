#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];

// 쿼리의 갯수가 10^5개 이므로 그때그때 찾으면 시간초과..
// 트리DP 이용해서 모든 정점에서의 서브트리 정점 갯수를 기록할 것

int dp[100001] = {};

bool visited[100001] = {};

void dfs(int cur){
    visited[cur] = true;
    dp[cur] = 1;
    for (int next: adj[cur]){
        if (visited[next]) continue;

        dfs(next);
        dp[cur] += dp[next];
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, r, q;
    cin>>n>>r>>q;
    int u, v;
    for (int i=1 ; i<n ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);

    for (int i=0 ; i<q ; i++){
        cin>>u;
        cout<<dp[u]<<"\n";
    }
    return 0;
}