#include <iostream>

using namespace std;

int n;
int w[16][16]; // 갈 수 없는 경우 w[i][j]=0
int dp[16][16];

void visit(int &bit, int num){
    bit = bit | (1<<num);
}

bool check(int bit, int num){
    return bit & (1<<num);
}

void dfs(int cur, int bit){
    visit(bit, cur);
    dp[]
    for (int next=0 ; next<n ; next++){
        if (w[cur][next]!=0 && !check(bit, next)){
            dfs(next, bit);
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        dp[i][i] = 0;
        for (int j=0 ; j<n ; j++){
            cin>>w[i][j];
        }
    }
    for (int i=0 ; i<n ; i++){
        dfs(i, 0);
    }
}