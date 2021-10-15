#include <iostream>

using namespace std;

char map[1000][1000];
int m,n;

bool isRange(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n);
}

int h_state(int i, int j){
    int ret = 0;
    if (map[i-1][j]=='X') ret += 2;
    if (map[i][j]=='X') ret += 1;
    return ret;
}

int v_state(int i, int j){
    int ret = 0;
    if (map[i][j-1]=='X') ret += 2;
    if (map[i][j]=='X') ret += 1;
    return ret;
}

// 공간 내부의 가로선 및 세로선을 전탐색
int main(void){
    cin>>m>>n;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    int answer = 0;
    int len = 0;
    // 가로선
    for (int i=1 ; i<m ; i++){
        for (int j=1 ; j<n ; j++){
            if (h_state(i,j)==1 || h_state(i,j)==2){
                if (h_state(i,j)==h_state(i,j-1)) len++;
                else {
                    // if (len/2>0) cout<<"[H]"<<i<<" "<<j<<": "<<len<<"\n";
                    answer += len/2;
                    len = 1;
                }
            }
            else {
                // if (len/2>0) cout<<"[H]"<<i<<" "<<j<<": "<<len<<"\n";
                answer += len/2;
                len = 0;
            }
        }
        answer += len/2;
        len = 0;
    }
    // 세로선
    for (int j=1 ; j<n ; j++){
        for (int i=1 ; i<m ; i++){
            if (v_state(i,j)==1 || v_state(i,j)==2){
                if (v_state(i,j)==v_state(i-1,j)) len++;
                else {
                    // if (len/2>0) cout<<"[V]"<<i<<" "<<j<<": "<<len<<"\n";
                    answer += len/2;
                    len = 1;
                }
            }
            else {
                // if (len/2>0) cout<<"[V]"<<i<<" "<<j<<": "<<len<<"\n";
                answer += len/2;
                len = 0;
            }
        }
        answer += len/2;
        len = 0;
    }
    cout<<answer;
    return 0;
}