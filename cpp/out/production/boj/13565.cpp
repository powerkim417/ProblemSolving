#include <iostream>

using namespace std;

int m, n;
char map[1000][1000];
bool visited[1000][1000] = {};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int nr, nc;

bool isRange(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n);
}

void dfs(int i, int j){
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        nr = i + dr[d];
        nc = j + dc[d];
        if (isRange(nr, nc) && map[nr][nc]=='0' && !visited[nr][nc]) dfs(nr, nc);
    }
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>m>>n;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    for (int j=0 ; j<n ; j++){
        if (map[0][j]=='0' && !visited[0][j]) dfs(0,j);
    }
    for (int j=0 ; j<n ; j++){
        if (visited[m-1][j]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}