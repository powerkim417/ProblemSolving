#include <iostream>

using namespace std;

int n, rain;
int map[100][100];
bool visited[100][100];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    int ni, nj;
    for (int d=0 ; d<4 ; d++){
        ni = i + dr[d];
        nj = j + dc[d];
        if (isRange(ni, nj) && map[ni][nj]>rain && !visited[ni][nj])
            dfs(ni, nj);
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    int ans = 1; // 아무데도 안잠겼을 때 1개 영역
    int temp;
    for (rain=1 ; rain<=99 ; rain++){ // 높이가 100부터이므로 비가 100 이상에선 다 잠김
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                visited[i][j] = false; // 방문 배열 초기화
            }
        }
        temp = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (map[i][j]>rain && !visited[i][j]){
                    temp++;
                    dfs(i, j);
                }
            }
        }
        if (temp>ans) ans = temp;
    }
    cout<<ans;
}