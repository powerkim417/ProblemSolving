#include <iostream>

using namespace std;

int dp[250][250*250]; // i까지 했고, j만큼의 여유시간이 있을 때 걸린 시간
// 100 2
// 100 2 일 경우 b가 4만큼의 할동안 a에게 4의 여유시간이 생김
// 3 200
/*
dp[0][2] = 2;
dp[0][100] = 100;
dp[1][4] = 4;
dp[1][98] = 98;
근데 a,b중 어디에 여분이 있는건지 표시해줘야 함
차원을 하나 더만들까?
*/
int main(void){
    int n;
    cin>>n;
    int t[n][2];
    for (int i=0 ; i<n ; i++){
        cin>>t[i][0]>>t[i][1];
    }
    dp[0][0]
}