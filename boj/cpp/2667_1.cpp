#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char map[25][25];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[25][25] = {};
int comp;

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    comp++;
    visited[i][j] = true;
    int ni, nj;
    for (int d=0 ; d<4 ; d++){
        ni = i + dr[d];
        nj = j + dc[d];
        if (isRange(ni, nj) && map[ni][nj] == '1' && !visited[ni][nj]){
            dfs(ni, nj);
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
    vector<int> v;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j] == '1' && !visited[i][j]){
                comp = 0;
                dfs(i, j);
                v.push_back(comp);
            }
        }
    }
    sort(v.begin(), v.end());
    int v_size = v.size();
    cout<<v_size<<"\n";
    for (int i=0 ; i<v_size ; i++){
        cout<<v[i]<<"\n";
    }
}