#include <iostream>
#include <vector>
#include <algorithm>

int m,n,k;
int map[100][100] = {};
bool visited[100][100] = {};

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int r, int c){
    if (r>=0 && r<m && c>=0 && c<n) return true;
    else return false;
}

int area;

void dfs(int i, int j){
    area++;
    visited[i][j] = true;
    int newi, newj;
    for (int d=0 ; d<4 ; d++){
        newi = i + dr[d];
        newj = j + dc[d];
        if (isRange(newi, newj) && map[newi][newj] == 0 && !visited[newi][newj]){
            dfs(newi, newj);
        }
    }
}

int main(void){
    cin>>m>>n>>k;
    int x1, y1, x2, y2;
    for (int i=0 ; i<k ; i++){
        cin>>y1>>x1>>y2>>x2;
        y2--;
        x2--;
        for (int x=x1 ; x<=x2 ; x++){
            for (int y=y1 ; y<=y2 ; y++){
                map[x][y] = 1;
            }
        }
    }
    vector<int> v;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[i][j]==0 && !visited[i][j]){
                area = 0;
                dfs(i, j);
                v.push_back(area);
            }
        }
    }
    sort(v.begin(), v.end());
    int size = v.size();
    cout<<size<<"\n";
    for (int i=0 ; i<size ; i++){
        cout<<v[i]<<" ";
    }
}