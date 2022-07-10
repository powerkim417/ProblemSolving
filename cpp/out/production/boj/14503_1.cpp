#include <iostream>

using namespace std;

int n, m;
int map[50][50];
bool cleaned[50][50] = {};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1}; // 북 동 남 서

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

int main(void){
    cin>>n>>m;
    int r,c,d;
    cin>>r>>c>>d;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    // 현재 위치: (r, c), 방향 d
    bool move; // 다음에 갈 곳을 찾았으면 true
    while (1){
        // 1. 현재 위치 청소
        cleaned[r][c] = true;
        // cout<<"("<<r<<", "<<c<<") cleaned, direction: "<<d<<"\n";
        // 2. 현재 방향 기준 왼쪽 = (d+3)%4
        move = false;
        for (int i=1 ; i<=4 ; i++){
            int nr = r + dr[(d+3*i)%4];
            int nc = c + dc[(d+3*i)%4];
            // cout<<"next location: ("<<nr<<", "<<nc<<")\n";
            if (isRange(nr, nc) && map[nr][nc]==0 && !cleaned[nr][nc]){
                r = nr;
                c = nc;
                d = (d+3*i)%4;
                move = true;
                break;
            }
            else {
                continue;
            }
        }
        // 다음에 갈 곳을 찾았으면 fail = false 이므로 while 처음으로 간다.
        if (!move){
            // c. 네 방향 모두 청소|벽인 경우 후진 후 다시 2번으로.
            r -= dr[d];
            c -= dc[d];
            // d. 후진도 안되면 종료
            if (map[r][c] == 1) break;
        }
        
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (cleaned[i][j]) answer++;
        }
    }
    cout<<answer;
    return 0;
}