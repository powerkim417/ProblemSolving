#include <iostream>

using namespace std;

int dp[1000];
// i를 포함하는 부분수열 중 index i 까지 최대값
// i를 포함하는 부분수열이므로 10 20 10 이면 1 2 1 로 뚝 떨어지는게 정상.

int main(void){
    int n;
    cin>>n;
    int a[n];
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    dp[0] = 1;
    for (int i=1 ; i<n ; i++){
        int max = 1;
        for (int j=0 ; j<i ; j++){
            if (a[i] > a[j]){ // i번째 수가 증가부분수열에 들어가지며,
                if (max < dp[j]+1) // 들어갔을 때의 결과가 최대면 갱신
                    max = dp[j] + 1;
            }
            // <해설>
            // j를 포함하는 최대부분수열에 a[i]가 들어가는지,
            // 만약 들어간다면 dp[j]+1을 dp[i]의 후보군으로 둔다.
        }
        dp[i] = max;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        // cout<<dp[i]<<" ";
        if (answer < dp[i]) answer = dp[i];
        /* dp[n-1] 자체가 답이 아니고
        나온 모든 값들 중 최대값이 답이 된다.
        1 2 3 1 이면 d[2]=3가 답이 되어야 하므로! */
    }
    // cout<<endl;
    cout<<answer;
}