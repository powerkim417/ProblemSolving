#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_TIME 50*50+1

using namespace std;

int n,m;
int map[50][50];
bool visited[50][50] = {};
int max_area; // 바이러스가 퍼져야 하는 공간의 수(map[i][j]==0)
int tot_virus;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

// 처음 풀이때 확인하지 못한 조건
// 활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.
// 근데 이건 그냥 바이러스가 통과한다고 생각해도 될듯

int main(void){
    cin>>n>>m;
    vector<pair<int, int>> virus;
    for (int i=0; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            if (map[i][j]==0) max_area++;
            if (map[i][j]==2) {
                tot_virus++;
                virus.push_back({i,j});
            }
        }
    }
    // tot_virus개의 바이러스 중 m개를 고르는 방식
    vector<int> choose;
    for (int i=0 ; i<tot_virus ; i++){
        // 처음 넣은 모양에서 출발하므로 처음부터 00.0011..11 형태로 넣어줘야 함
        if (i<tot_virus-m) choose.push_back(0);
        else choose.push_back(1);
    }
    int min_time = MAX_TIME;
    int time;
    int cnt;
    do {
        // for (int i=0 ; i<tot_virus ; i++){
        //     cout<<choose[i];
        // }
        // cout<<"\n";
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                visited[i][j] = false;
            }
        }
        time = 0;
        queue<pair<int, int>> q;
        // 비활성 바이러스는 빈 공간과 유사하나, 같게 보면 안됨.
        // 마지막으로 도달할 공간이 빈 공간인 것(1 더가야 함)과, 비활성 바이러스인 경우(이미 끝)는 결과가 다르기 때문!
        for (int i=0 ; i<tot_virus ; i++){
            if (choose[i]==1){ // 활성 바이러스
                q.push(virus[i]);
                visited[virus[i].first][virus[i].second] = true;
            }
        }
        
        // BFS
        cnt = 0;
        while (!q.empty()){
            if (cnt == max_area) break;
            int q_size = q.size();
            for (int qs=0 ; qs<q_size ; qs++){
                pair<int, int> cur = q.front();
                q.pop();
                for (int d=0 ; d<4 ; d++){
                    int ni = cur.first+dr[d];
                    int nj = cur.second+dc[d];
                    if (isRange(ni, nj) && map[ni][nj]!=1 && !visited[ni][nj]){
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                        if (map[ni][nj]==0) cnt++;
                    }
                }
            }
            time++;
        }
        if (cnt < max_area) {
            // cout<<" FAIL\n";
            continue;
        }
        if (cnt == max_area){
            // cout<<" "<<time<<"\n";
            if (time < min_time){
                min_time = time;
            }
        }
    } while (next_permutation(choose.begin(), choose.end()));
    if (min_time == MAX_TIME){
        cout<<"-1";
    }
    else {
        cout<<min_time;
    }
    return 0;
}