#include <iostream>
#include <vector>

using namespace std;

int dp[100001] = {};
vector<int> adj[100001];

void dfs(int cur){
    for (int next: adj[cur]){
        dp[next] += dp[cur];
        dfs(next);
    }
}

// 트리 DP
// 트리 DP의 핵심은 그때그때 전파하는 것이 아니고(시간초과)
// 값을 하나하나 적재한 뒤 한번의 전파에서 값을 쌓아나가야 함
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int p;
    for (int i=1 ; i<=n ; i++){
        cin>>p;
        if (i!=1) adj[p].push_back(i);
    }
    int num, w;
    for (int i=0 ; i<m ; i++){
        cin>>num>>w;
        dp[num] += w;
    }
    dfs(1);
    for (int i=1 ; i<=n ; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}