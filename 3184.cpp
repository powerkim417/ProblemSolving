#include <iostream>

using namespace std;

char map[250][250];
bool visited[250][250];
int sheep = 0, wolf = 0;
int temp_s, temp_w;
int r,c;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

bool isRange(int i, int j){
    if (i>=0 && i<r && j>=0 && j<c) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    if (map[i][j] == 'v') temp_w++;
    else if (map[i][j] == 'o') temp_s++;
    for (int d=0 ; d<4 ; d++){
        int newi = i + dr[d];
        int newj = j + dc[d];
        if (isRange(newi, newj) && !visited[newi][newj] && map[newi][newj] != '#')
            dfs(newi, newj);
    }
}

int main(void){
    cin>>r>>c;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>map[i][j];
        }
    }
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (!visited[i][j] && map[i][j] != '#'){
                // cout<<"DFS on ("<<i<<", "<<j<<") starts\n";
                temp_s = 0;
                temp_w = 0;
                dfs(i, j);
                if (temp_s > temp_w) sheep += temp_s;
                else wolf += temp_w;
            }
        }
    }
    cout<<sheep<<" "<<wolf;
}