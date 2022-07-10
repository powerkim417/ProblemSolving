#include <iostream>

using namespace std;

int n;
int p[10001];
int dp[10001]; // i개 팩까지 확인했을 때 최소값

int main(void){
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>p[i]; // p[i]의 가격을 지불하고 i개의 카드를 가짐
    }
    dp[1] = p[1];
    for (int i=2 ; i<=n ; i++){
        dp[i] = p[i]; // 0개까지 산 상태에서 i개짜리 팩 하나로만 구성할 때(초기값)
        // dp[i]는 j개까지 샀을 때의 최소값에서 i-j개짜리 팩을 산 값을 비교했을 때 그중 가장 최소
        for (int j=1 ; j<i ; j++){
            if (dp[i] > dp[j] + p[i-j]) dp[i] = dp[j] + p[i-j];
        }
    }
    cout<<dp[n];
    return 0;
}