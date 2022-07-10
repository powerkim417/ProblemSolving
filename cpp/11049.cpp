#include <iostream>

using namespace std;

int num[501];
int dp[500][500]; // 행렬 크기, 시작점
int main(void){
    int n;
    cin>>n;
    // num: 겹치는 크기를 제외한 행렬의 크기를 일렬로! 3개 연속 곱하면 됨.
    // num[n+1]. 0~n 있음.
    for (int t=0 ; t<n ; t++){
        int r,c;
        cin>>num[t]>>num[t+1];
    }

    for (int i=0 ; i<n ; i++){
        dp[1][i] = 0;
    }
    for (int i=0 ; i<n-1 ; i++){
        dp[2][i] = num[i]*num[i+1]*num[i+2];
    }

    for (int i=3 ; i<=n ; i++){
        for (int j=0 ; j<n-i+1 ; j++){
            int min = 2147483647;
            // dp[i][j]: i개의 행렬 합. j번째 ~ j+i-1번째 행렬.
            // n개의 행렬을 곱하는 방법을 (1)(n-1), (2)(n-2), ..., (n-1)(1) 와 같이 나눈다. 
            for (int k=1 ; k<=i-1 ; k++){
                int temp = dp[k][j] + dp[i-k][j+k] + num[j]*num[j+k]*num[j+i];
                if (temp < min) min = temp;
            }
            dp[i][j] = min;
        }
    }

    cout<<dp[n][0];
    
    // m[n] = (A1...An-1)An || (A1..An-2)(An-1An) || .. || A1(A2..An)

}