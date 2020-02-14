#include <iostream>

using namespace std;

char map[100][100];
bool h[100] = {};
bool v[100] = {};

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++) cin>>map[i][j];
    }
    bool hflag = false;
    bool vflag = false;
    int h_ans = 0, v_ans = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j]=='X') hflag = false;
            if (j!=n-1 && map[i][j]=='.' && map[i][j+1]=='.' && !hflag) {
                h_ans++;
                hflag = true; // 현재 탐색중인 자리가 이어지고 있는 누울자리
            }
        }
        hflag = false; // 다음 행에선 초기화
    }
    // 세로 자리는 column 먼저 포문 돌림
    for (int j=0 ; j<n ; j++){
        for (int i=0 ; i<n ; i++){
            if (map[i][j]=='X') vflag = false;
            if (i!=n-1 && map[i][j]=='.' && map[i+1][j]=='.' && !vflag) {
                v_ans++;
                vflag = true;
            }
        }
        vflag = false;
    }
    cout<<h_ans<<" "<<v_ans;
    return 0;
}