#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n, k;
int map[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[100][100];
int cnt;
int sz;

bool inRange(int i, int j){
    if (i>=0 && i<m && j>=0 && j<n) return true;
    else return false;
}

int dfs(int i, int j){
    visited[i][j] = true;
    map[i][j] = ++sz;
    int ni, nj;
    for (int d=0 ; d<4 ; d++){
        ni = i+dy[d];
        nj = j+dx[d];
        if (inRange(ni, nj) && map[ni][nj] != 0 && !visited[ni][nj]){
            dfs(ni, nj);
        }
    }
    return sz;
}

int main(void){
    cin>>m>>n>>k;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            map[i][j] = 1;
        }
    }
    int x1, y1, x2, y2;
    for (int i=0 ; i<k ; i++){
        cin>>x1>>y1>>x2>>y2;
        for (int y=y1 ; y<y2 ; y++){
            for (int x=x1 ; x<x2 ; x++){
                map[y][x] = 0;
            }
        }
    }
    cnt = 0;
    sz = 0;
    vector<int> sizes;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j] != 0 && !visited[i][j]){
                cnt++;
                sz = 0;
                sizes.push_back(dfs(i, j));
            }
        }
    }
    cout<<cnt<<" ";
    sort(sizes.begin(), sizes.end());
    int s = sizes.size();
    for (int i=0 ; i<s ; i++){
        cout<<sizes[i]<<" ";
    }

    // for (int i=0 ; i<m ; i++){
    //     for (int j=0 ; j<n ; j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}