#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
    int r;
    int c;
};

int n, m;
bool visited[8][8];
int map[8][8], usemap[8][8];
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

void dfs(int i, int j){
    visited[i][j] = true;
    usemap[i][j] = 2;
    for (int k=0 ; k<4 ; k++){
        int newi = i+r[k];
        int newj = j+c[k];
        if (newi >= 0 && newi < n
        && newj >= 0 && newj < m
        && usemap[newi][newj] != 1
        && !visited[newi][newj]){
            dfs(newi, newj);
        }
    }
}

int main(void){
    cin>>n>>m;
    vector<point> wall;
    vector<int> select;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]==0) wall.push_back({i,j});
        }
    }
    int total_wall = wall.size();
    // select 보조수열을 이용하여 m*n C 3 의 조합을 모두 구함
    // 0을 먼저 넣는다
    for (int i=0 ; i<total_wall-3 ; i++){
        select.push_back(0);
    }
    for (int i=0 ; i<3 ; i++){
        select.push_back(1);
    }
    int max = 0;
    do { // 벽을 놓는 모든 경우의 수를 brute-force로
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                usemap[i][j] = map[i][j];
                visited[i][j] = false;
            }
        }
        for (int i=0 ; i<total_wall ; i++){
            if (select[i] == 1){
                usemap[wall[i].r][wall[i].c] = 1;
            }
        }
        // 벽 세팅 완료
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (!visited[i][j] && usemap[i][j]==2){
                    dfs(i, j);
                }
            }
        }
        // 감염 확산 완료
        int temp = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (usemap[i][j] == 0) temp++;
            }
        }
        if (temp > max) max = temp;
    } while (next_permutation(select.begin(), select.end()));
    cout<<max;
}