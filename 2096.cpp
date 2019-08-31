#include <iostream>

using namespace std;

int max_dp[2][3], min_dp[2][3]; // 2개의 칸만으로 공간을 재활용.
// 첫번째 인덱스에는 n%2가 들어갈 예정
// 두번째 인덱스에는 0,1,2: 각각 왼쪽,가운데,오른쪽을 택한 경우
// n번째 칸까지 내려갔고, 특정 위치로 내려왔을 때의 최대값

int max(int a, int b){
    return (a>b)?a:b;
}

int max(int a, int b, int c){
    int t = (a>b)?a:b;
    return (t>c)?t:c; 
}

int min(int a, int b){
    return (a<b)?a:b;
}

int min(int a, int b, int c){
    int t = (a<b)?a:b;
    return (t<c)?t:c; 
}

int main(void){
    int n;
    cin>>n;
    int a,b,c;
    for (int i=0 ; i<3 ; i++) {
        max_dp[0][i] = 0;
        min_dp[0][i] = 0; // 처음엔 얘도 0...
    }
    for (int t=1 ; t<=n ; t++){
        cin>>a>>b>>c;
        max_dp[t%2][0] = max(max_dp[(t-1)%2][0], max_dp[(t-1)%2][1]) + a;
        max_dp[t%2][1] = max(max_dp[(t-1)%2][0], max_dp[(t-1)%2][1], max_dp[(t-1)%2][2]) + b;
        max_dp[t%2][2] = max(max_dp[(t-1)%2][1], max_dp[(t-1)%2][2]) + c;
        
        min_dp[t%2][0] = min(min_dp[(t-1)%2][0], min_dp[(t-1)%2][1]) + a;
        min_dp[t%2][1] = min(min_dp[(t-1)%2][0], min_dp[(t-1)%2][1], min_dp[(t-1)%2][2]) + b;
        min_dp[t%2][2] = min(min_dp[(t-1)%2][1], min_dp[(t-1)%2][2]) + c;
    }
    int max_answer = max(max_dp[n%2][0], max_dp[n%2][1], max_dp[n%2][2]);
    int min_answer = min(min_dp[n%2][0], min_dp[n%2][1], min_dp[n%2][2]);
    cout<<max_answer<<" "<<min_answer;
}