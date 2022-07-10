#include <iostream>

using namespace std;

int n;
char map[100][100];
bool visited[100][100] = {};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (isRange(ni, nj) && !visited[ni][nj] && map[i][j]==map[ni][nj]){
            dfs(ni, nj);
        }
    }
}

void dfs_colorblind(int i, int j){ // 적록색약 dfs
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (isRange(ni, nj) && !visited[ni][nj]){
            if ((map[i][j] == 'R' && map[ni][nj] != 'B')
                || (map[i][j] == 'G' && map[ni][nj] != 'B')
                || (map[i][j] == 'B' && map[ni][nj] == 'B'))
                dfs_colorblind(ni, nj);
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
    int comp = 0;
    // 비적록색약
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (!visited[i][j]) {
                comp++;
                dfs(i, j);
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++) visited[i][j] = false;
    }
    cout<<comp<<" ";

    // 적록색약
    comp = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (!visited[i][j]) {
                comp++;
                dfs_colorblind(i, j);
            }
        }
    }
    cout<<comp;
}