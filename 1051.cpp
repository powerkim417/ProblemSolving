#include <iostream>

using namespace std;

char map[50][50];

int min(int a, int b){
    return (a>b)?b:a;
}

int main(void){
    int n, m;
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    int answer = min(n, m);
    while (answer > 1){
        for (int i=0 ; i+(answer-1)<n ; i++){
            for (int j=0 ; j+(answer-1)<m ; j++){
                // cout<<map[i][j]<<" ";
                // cout<<map[i+answer-1][j]<<" ";
                // cout<<map[i][j+answer-1]<<" ";
                // cout<<map[i+answer-1][j+answer-1]<<"\n";
                if (map[i][j]==map[i+answer-1][j] &&
                 map[i+answer-1][j]==map[i+answer-1][j+answer-1] &&
                 map[i+answer-1][j+answer-1]==map[i][j+answer-1]){
                     cout<<answer*answer;
                     return 0;
                 }
            }
        }
        answer--;
    }
    cout<<answer*answer; // answer == 1
    return 0;
}