#include <iostream>

using namespace std;

int dp[16];

int main(void){
    int n;
    cin>>n;
    int t[16], p[16];
    for (int i=1 ; i<=n ; i++){
        cin>>t[i]>>p[i];
        // t[i] += i; // t[i]에는 i번째 상담을 받고 새 상담을 받을 수 있게 되는 날짜가 들어감
        if (i+t[i] > n+1) p[i] = 0; // 기간 내에 못끝내는 상담은 받지 않도록
        // 7일차 + 1일치상담(7+1=8)은 가능해야 한다..

        dp[i] = p[i]; // 일단 그 날만 상담을 받는 걸로 초기화..
    }

    // dp[n]: n일차의 상담을 "받았을" 경우의 최대값

    /*
    이번 문제의 경우
    dp[n]이 답이 아니라,
    dp[1]~dp[n] 중 가장 큰 값이 답이 된다.
    */

    // 4일까지의 최대값이 되는 후보
    // 4일 상담비(기준)
    // 1일까지의 최대값 + 4일 상담비
    // 2일까지의 최대값 + 4일 상담비
    // 3일까지의 최대값 + 4일 상담비

    for (int i=2 ; i<=n ; i++){
        for (int j=1 ; j<i ; j++){
            // i일에 p[i]를 추가한 값으로 갱신하려면, i일에 일이 없는 상태여야 함
            // 즉, j일의 일을 수락했다면 i=j+t[j]일부터 가능
            if (i >= j + t[j]){
                if (dp[j]+p[i] > dp[i]) dp[i] = dp[j]+p[i];
            }
        }
    }
    // for (int i=1 ; i<=n ; i++){
    //     cout<<dp[i]<<"\n";
    // }
    int answer = 0;
    for (int i=1 ; i<=n ; i++){
        if (answer < dp[i]) answer = dp[i];
    }
    cout<<answer;
    return 0;
}