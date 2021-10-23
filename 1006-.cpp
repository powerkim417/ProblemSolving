#include <iostream>

using namespace std;

int area[10000][2]; // 안, 밖
int dp[10001][3]; // 안, 밖, 둘다

void clear_dp(){
    for (int i=0 ; i<10001 ; i++){
        for (int j=0 ; j<2 ; j++){
            dp[i][3] = 0;
        }
    }
}

int main(void){
    int t;
    cin>>t;
    int n, w;
    while (t--){
        cin>>n>>w;
        for (int j=0 ; j<=1 ; j++){
            for (int i=0 ; i<n ; i++){
                cin>>area[i][j];
            }
        }
        int answer = 2*n+1;
        // 선형으로 dp한 경우
        clear_dp();
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = (area[0][0]+area[0][1] <= w);
        for (int i=1 ; i<n ; i++){
            dp[i][0] = 
        }
        
        // 처음과 끝이 밖만 연결된 경우

        // 처음과 끝이 안만 연결된 경우

        // 처음과 끝이 둘다 연결된 경우
    }
}