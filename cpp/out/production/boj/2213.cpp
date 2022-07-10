#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w[10001];
vector<int> adj[10001];

bool visited[10001] = {};
int dp[10001][2] = {}; // i번째 노드를 포함하지 않거나, 포함하거나

int max(int a, int b){
    return (a>b)?a:b;
}

void dfs(int cur){
    visited[cur] = true;

    dp[cur][0] = 0;
    dp[cur][1] = w[cur];
    for (int next: adj[cur]){
        if (visited[next]) continue;
        dfs(next);
        // 본인 미포함인 경우 자식들의 dp값중 가장 큰 값(포함 또는 미포함)
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        // 본인 포함인 경우 dp[자식][0]값들을 모두 합한 값
        dp[cur][1] += dp[next][0];
    }
}

vector<int> ret;

// 역추적
void trace(int cur, bool isIn){
    visited[cur] = true;
    if (isIn){
        ret.push_back(cur);
        for (int next: adj[cur]){
            if (visited[next]) continue;
            // cur의 자식은 모두 미포함
            trace(next, false);
        }
    }
    else {
        for (int next: adj[cur]){
            if (visited[next]) continue;
            if (dp[next][0] > dp[next][1]){
                trace(next, false);
            }
            else {
                trace(next, true);
            }
        }
    }
}

int main(void){
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>w[i];
    }
    int u, v;
    while (cin>>u>>v){
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    dfs(1); // 일반성을 잃지 않고 1번 노드를 루트로 간주하고 돌려도 됨

    // trace에서 한번 더 DFS를 돌 것이므로 visited 배열 초기화
    for (int i=1 ; i<=n ; i++) visited[i] = false;
    if (dp[1][0] > dp[1][1]){
        cout<<dp[1][0]<<"\n";
        trace(1, false);
    }
    else {
        cout<<dp[1][1]<<"\n";
        trace(1, true);
    }
    sort(ret.begin(), ret.end());
    for (int r: ret){
        cout<<r<<" ";
    }
    return 0;
}