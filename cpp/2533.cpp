#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[1000001];
int dp[1000001][2] = {}; // i번째 노드가 EA가 아니거나, EA거나

bool visited[1000001] = {};

int min(int a, int b) {
    return (a>b)?b:a;
}

// 양방향 그래프지만, 임의의 점을 루트로 정하고 DFS로 탐색하면 단방향 트리를 탐색하는 것과 같다.
void dfs(int cur) {
    visited[cur] = true;

    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (int next: adj[cur]){
        if (visited[next]) continue;
        // 해당 노드의 자식들만 본다

        dfs(next);
        
        // 내가 EA가 아니면, 내 친구들이 모두 EA여야 함
        dp[cur][0] += dp[next][1];    
        // 내가 EA라면, 내 친구들은 EA여도 되고 아니어도 됨
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

// 트리DP
int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    int u, v;
    for (int i=1 ; i<n ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); // 일반성을 잃지 않고 1을 루트로 삼고 탐색
    cout<<min(dp[1][0], dp[1][1]);
    return 0;
}