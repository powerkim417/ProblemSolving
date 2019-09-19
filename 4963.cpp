#include <iostream>

using namespace std;

int w,h;
int map[50][50];
bool visited[50][50];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inRange(int i, int j){
    if (i>=0 && i<h && j>=0 && j<w) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    int ni, nj;
    for (int d=0 ; d<8 ; d++){
        ni = i + dr[d];
        nj = j + dc[d];
        if (inRange(ni, nj) && map[ni][nj] == 1 && !visited[ni][nj]){
            dfs(ni, nj);
        }
    }
}

int main(void){
    while (1){
        cin>>w>>h;
        if (w==0 && h==0) break;
        for (int i=0 ; i<h ; i++){
            for (int j=0 ; j<w ; j++){
                visited[i][j] = false;
                cin>>map[i][j];
            }
        }
        int cnt = 0;
        for (int i=0 ; i<h ; i++){
            for (int j=0 ; j<w ; j++){
                if (map[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }    
            }
        }
        cout<<cnt<<"\n";
    }
}

