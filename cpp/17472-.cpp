#include <iostream>

using namespace std;

int n, m;
int map[10][10];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int comp = 0;
bool visited[10][10] = {};

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

void dfs(int i, int j){
    visited[i][j] = true;
    map[i][j] = comp;
    if (i+1<n && map[i+1][j]!=0) dfs(i+1, j);
    if (j+1<m && map[i][j+1]!=0) dfs(i, j+1);
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (map[i][j] != 0 && !visited[i][j]) {
                comp++;
                dfs(i, j);
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }

    // 섬은 comp개 있음
}