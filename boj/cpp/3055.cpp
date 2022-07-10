#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char map[50][50];
bool visited[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int i, int j){
    if (i>=0 && i<R && j>=0 && j<C) return true;
    else return false;
}

int main(void){
    cin>>R>>C;
    queue<pair<int, int>> q;
    vector<pair<int, int>> water;
    for (int i=0 ; i<R ; i++){
        for (int j=0 ; j<C ; j++){
            visited[i][j] = false;
            cin>>map[i][j];
            if (map[i][j] == 'S'){
                q.push({i, j});
                visited[i][j] = true;
            }
            if (map[i][j] == '*'){
                water.push_back({i, j});
            }
        }
    }
    int time = 0;
    int ni, nj;
    while (!q.empty()){
        // cout<<"------\n";
        int q_size = q.size();    
        // 디버그 출력   
        // for (int i=0 ; i<R ; i++){
        //     for (int j=0 ; j<C ; j++){   
        //         cout<<map[i][j];
        //     }
        //     cout<<endl;
        // }    
        // 물 퍼짐
        for (auto w: water){
            if (map[w.first][w.second] == '*'){
                for (int d=0 ; d<4 ; d++){
                    ni = w.first + dr[d];
                    nj = w.second + dc[d];
                    if (inRange(ni, nj) && (map[ni][nj] == '.' || map[ni][nj] == 'S')) {
                        map[ni][nj] = '*';
                        water.push_back({ni, nj});
                    }
                }
            }
        }
        // 같은 레벨에 대해 출력
        for (int qs=0 ; qs<q_size ; qs++){
            pair<int, int> cur = q.front();
            // cout<<cur.first<<" "<<cur.second<<endl;
            if (map[cur.first][cur.second] == 'D'){
                cout<<time;
                return 0;
            }
            q.pop();
            for (int d=0 ; d<4 ; d++){
                ni = cur.first + dr[d];
                nj = cur.second + dc[d];
                if (inRange(ni, nj) && map[ni][nj] != '*' && map[ni][nj] != 'X' && !visited[ni][nj]){
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        time++;
    }
    // 도달 못하고 나와버림
    cout<<"KAKTUS";
    return 0;
}