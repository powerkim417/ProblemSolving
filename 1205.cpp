#include <iostream>

using namespace std;

int board[51];

int main(void){
    int n, score, p;
    cin>>n>>score>>p;
    for (int i=1 ; i<=p ; i++){
        if (i<=n) cin>>board[i];
        else board[i] = -1;
    }
    int answer = 1;
    for (int i=1 ; i<=p ; i++){
        if (board[i] > score) answer = i+1;
        else break;
    }
    if (answer > p || board[p] == score) cout<<"-1";
    else cout<<answer;
    return 0;
}