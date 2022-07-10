#include <iostream>

using namespace std;

int dp[100001]; // 가방 한도가 j인 상황에서 최대 가치값

int max(int a, int b){
    return (a>b)?a:b;
}

// DP 냅색 문제를 1차원 배열로 최적화한 풀이!!
// https://hevton.tistory.com/362
/*
특징
배낭의 무게보다 물건이 더 무거워서 담지 못하는 경우에 대한 처리 필요 X(중첩되면서 값이 이미 들어있음)
이전 물건까지의 최대값을 dp[i-1]에서 가져오는게 아니라 자기자신에서 가져옴(이미 dp[j]에 들어있음)
무게를 최대값부터 1까지 역으로 탐색해야 함

무게를 정방향 탐색하면 안되는 이유
n=2, k=6, 각각 무게1 가치2, 무게1 가치3의 물건을 담을 때
정방향으로 탐색할 경우 첫번째 물건에서
dp[1] = max(dp[1], dp[1-1]+2) = 2
dp[2] = max(dp[2], dp[2-1]+2) = 4
무게가 2일 때 첫번째 물건을 이미 담은 상태의 값을 사용하여 한번 더 담은 케이스가 최대값이 되어버렸다
즉, "현재 단계에서 업데이트한 dp값은 사용되지 못하도록 하는 것"이 핵심
*/
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    int w[101], v[101];
    for (int i=1 ; i<=n ; i++){
        cin>>w[i]>>v[i];
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=k ; j>=1 ; j--){
            if (j>=w[i]) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            // 1차원으로 덮어쓰기 때문에 j<w[i]인 경우에 대해 값을 채워줄 필요가 없음
        }
    }
    cout<<dp[k];
    return 0;
}