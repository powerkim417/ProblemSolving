#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000][2];
// 처음 i개까지의 수의 연속된 합 중 최대, i번째 수를 안쓴다0 쓴다1  

int max(int a, int b, int c){
    int t = (a>b)?a:b;
    return (t>c)?t:c;
}

int main(void){
    int n;
    cin>>n;
    int a[n];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i=1 ; i<n ; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1], 0);
        // i-1까지중 최대값 또는 0(i-1까지의 최대값이 음수일 경우 다 버림)
        dp[i][1] = max(dp[i-1][1], 0) + a[i];
        // i-1까지중 최대값이고, i-1번째를 택한 값이거나 0(전자가 음수일 경우 다 버림) + i번째 수
    }
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<2 ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int answer = max(dp[n-1][0], dp[n-1][1]);

    // 아무것도 못 고른 경우 예외처리 방법 1
    /* 만약 양수가 하나라도 있다면 그 양수를 골랐을 테니 answer > 0.
    그러나 answer = 0이 나올 경우
    수열의 모든 수가 0 이하라는 답이 나온다.
    
    i) 모든 수가 0 이하(0 포함)
    0 하나를 골랐을 때 answer = 0
    ii) 모든 수가 음수
    수열 중 가장 큰 값 하나를 골라서 그 수가 answer 가 된다.
    
    이렇게 두 경우를 한번에 해결하기 위해
    answer = 0일 때 answer = (가장 큰 수)으로 해주면
    예외 처리가 가능하다. */

    if (answer == 0){
        int M = -1001;
        for (int i=0 ; i<n ; i++){
            if (a[i]>M) M = a[i];
        }
        answer = M;
    }
    cout<<answer;
}