#include <iostream>

using namespace std;

int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[500][500];
bool visited[500][500] = {};
int answer = 0;

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

// 모든 모양과 회전과 대칭에 대해 브루트 포스로 해도 되지만,
// 모든 위치에 대해 백트래킹 dfs를 사용하면 ㅗ모양을 제외하고 전부 볼 수 있음
// ㅗ 모양은 dfs로 따로 처리하기 어려우니 브루트 포스로...

void dfs(int i, int j, int cnt, int cur){
    cur += map[i][j];
    if (cnt==4){
        if (cur>answer) answer = cur;
        return;
    }

    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i+dr[d];
        int nj = j+dc[d];
        if (isRange(ni, nj) && !visited[ni][nj]){
            dfs(ni, nj, cnt+1, cur);
        }
    }
    visited[i][j] = false;
}

int searchT(int i, int j, int dir){
    // 여기서 i,j는 해당 테트로미노의 좌표중 가장 왼쪽 위(i*m+j가 가장 작은 위치)로 한다.
    int ret=0; // 범위에 안맞는 경우는 결과에 영향 안미치게 그냥 0 반환
    switch (dir){
        case 0: // ㅏ
        if (isRange(i+2, j) && isRange(i+1, j+1)){
            ret = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j];
        }
        break;
        case 1: // ㅓ
        if (isRange(i+2, j) && isRange(i+1, j-1)){
            ret = map[i][j]+map[i+1][j-1]+map[i+1][j]+map[i+2][j];
        }
        break;
        case 2: // ㅗ
        if (isRange(i+1, j-1) && isRange(i+1, j+1)){
            ret = map[i][j]+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1];
        }
        break;
        case 3: // ㅜ
        if (isRange(i, j+2) && isRange(i+1, j+1)){
            ret = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1];
        }
        break;
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    // ㅗ모양 제외 모든 케이스 확인
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            dfs(i, j, 1, 0);
        }
    }
    // ㅗ모양 확인
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            for (int d=0 ; d<4 ; d++){
                int temp = searchT(i, j, d);
                if (temp>answer) answer = temp;
            }
        }
    }

    cout<<answer;
    return 0;
}