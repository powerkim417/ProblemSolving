#include <iostream>

using namespace std;

int n;
int map[100][100];
bool visited[100][100];
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};
int rain;

bool inRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    for (int m=0 ; m<4 ; m++){
        int newi = i + r[m];
        int newj = j + c[m];
        if (inRange(newi, newj) && map[newi][newj] > rain && !visited[newi][newj]){
            dfs(newi, newj);
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    int max = 0;
    for (rain=0 ; rain<=100 ; rain++){ // 0: 아무지역도 물에 잠기지 않을 때ㄹㅇ
        int cnt = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                visited[i][j] = false;
            }
        }
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (map[i][j] > rain && !visited[i][j]){
                    // 그림에서 흰 공간들에 대한 dfs 탐색
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        if (cnt == 0) break;
        if (cnt > max) max = cnt;
    }
    cout<<max;
}