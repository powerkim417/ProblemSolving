#include <iostream>
#include <vector>

using namespace std;

int dp[100001] = {};
int p[100001] = {};
bool visited[100001] = {};

// 직속 상사의 번호는 자신의 번호보다 작기 때문에
// i=1~n에 대해 이 함수를 실행할 때, 위에서 내려오는 모든 칭찬값이 다 확정됨이 보장됨
int get_cmpl(int num){
    // if (num==1) return 0;
    // return dp[num] += dp[p[num]];

    // 직속 상사 번호가 자신보다 클 경우도 고려한 코드(재귀)
    if (num==1) return 0;
    if (visited[num]) return dp[num];
    visited[num] = true;
    return dp[num] += get_cmpl(p[num]);
}

// 그냥 DP로도 풀 수 있음(top-down)
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    for (int i=1 ; i<=n ; i++){
        cin>>p[i];
    }
    int num, w;
    for (int i=0 ; i<m ; i++){
        cin>>num>>w;
        dp[num] += w;
    }
    for (int i=1 ; i<=n ; i++){
        cout<<get_cmpl(i)<<" ";
    }
    return 0;
}