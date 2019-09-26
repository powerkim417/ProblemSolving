#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000][1000]; // dp[i][j]: 첫번째의 i까지, 두번째의 j까지 문자열중 겹치는 글자 수

int max(int a, int b, int c){
    int t = (a>b)?a:b;
    return (t>c)?t:c;
}

int main(void){
    string a,b;
    cin>>a>>b;
    int len_a = a.size();
    int len_b = b.size();
    dp[0][0] = (a[0]==b[0]) ? 1 : 0;
    for (int i=1 ; i<len_a ; i++){
        dp[i][0] = (a[i]==b[0]) ? 1 : dp[i-1][0]; // 맞으면 무조건 1이고, 아니면 이전과 같은 값 유지
    }
    for (int j=1 ; j<len_b ; j++){
        dp[0][j] = (a[0]==b[j]) ? 1 : dp[0][j-1]; // 맞으면 무조건 1이고, 아니면 이전과 같은 값 유지
    }
    for (int i=1 ; i<len_a ; i++){
        for (int j=1 ; j<len_b ; j++){
            // 중요 IDEA. 이 문제는 state보다 점화식이 더 어려웠다.
            if (a[i]==b[j]) dp[i][j] = dp[i-1][j-1] + 1; // 지금 보는 두 위치가 같은 경우: i-1 j-1 값에 1을 추가
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 다른 경우: 의미없는 비교. i-1,j이나 i,j-1에서 더 발전한게 없으므로 두 값중 큰 값으로 채움
        }
    }
    // for (int i=0 ; i<len_a ; i++){
    //     for (int j=0 ; j<len_b ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[len_a-1][len_b-1];
}