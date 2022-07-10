#include <iostream>

using namespace std;

int n, m;
int map[100][100]; // 치즈: 1, 내부빈공간: 0, 외부공기: -1, 다음턴에 녹을 치즈: -2

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[100][100] = {};

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

// 이번에 공기 확인 부분은 dfs로 해볼것
void dfs(int r, int c){
    visited[r][c] = true;
    map[r][c] = -1;
    for (int d=0 ; d<4 ; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (!isRange(nr, nc)) continue;
        // 외부 공기 변환
        if (map[nr][nc]==0 || map[nr][nc]==-1){ // 다음 위치의 map이 0이나 -1일 때 방문
            if (!visited[nr][nc]) dfs(nr, nc);
        }
        else { // 다음 위치가 치즈일 때
            map[nr][nc] = -2;
        }
    }
}

// 2638번 문제는 두면이 닿으면 녹으나, 이 문제는 한면만 닿아도 녹음
// 이번 문제는 녹는 부분을 결정하기 위해 주변 공기를 기준으로 삼아도 됨(공기의 주변이 치즈라면 그 치즈는 이번에 녹음)
int main(void){
    cin>>n>>m;
    int total = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]==1) total++;
        }
    }
    int cnt;
    int time = 0;
    while (1){
        time++;
        // 1. 외부공기는 -1로 변환
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                visited[i][j] = false;
            }
        }
        dfs(0, 0);
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         if (map[i][j] == -2) cout<<"C ";
        //         else if (map[i][j] == -1) cout<<"- ";
        //         else cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        // 2. 치즈 녹음
        cnt = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j]==-2){
                    cnt++;
                    total--;
                    map[i][j] = -1;
                }
            }
        }

        // 3. 다 녹은 경우 이번 회에 녹은 치즈의 수 반환
        if (total == 0) break;
    }
    cout<<time<<"\n"<<cnt;
    return 0;
}