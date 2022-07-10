#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, g, r;
int map[50][50];
bool flower[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> land;
vector<int> choose; // land.size()-g-r 개의 0, g개의 1, r개의 2
int answer = 0;
int visit_time[50][50][2]; // 좌표, isGreen
struct point {
    int r;
    int c;
    bool isGreen;
};
queue<point> q; // 좌표, isGreen

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

/* BFS인데, 다른 문제들보다 특별한 점이 있다면
1. 배양액이 가능한 공간들 중 몇개를 고르는게 아니라 빨간 배양액, 초록 배양액을 넣을 공간 두 종류를 골라야 한다는 점과,
2. 이렇게 다른 두 종류의 배양액 위치를 하나의 queue에 넣어서 돌린다는 점!
*/
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>g>>r;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]==2) land.push_back({i, j});
        }
    }
    int ls = land.size();
    for (int i=0 ; i<ls ; i++){ // next_permutation을 이용해 000111 이 아닌 00011122 로도 뽑을 수 있음!
        if (i<ls-g-r) choose.push_back(0); // 배양액 X
        else if (i<ls-r) choose.push_back(1); // 배양액 G 
        else choose.push_back(2); // 배양액 R
    }
    int temp;

    do {
        temp = 0; // 이번 경우에서 피우는 꽃의 갯수
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                visit_time[i][j][0] = -1;
                visit_time[i][j][1] = -1;
                flower[i][j] = false;
            }
        }
        for (int i=0 ; i<ls ; i++){
            if (choose[i]==1) {
                q.push({land[i].first, land[i].second, true});
                visit_time[land[i].first][land[i].second][true] = 0;
            }
            else if (choose[i]==2) {
                q.push({land[i].first, land[i].second, false});
                visit_time[land[i].first][land[i].second][false] = 0;
            }
        }
        int time = 1;
        while (!q.empty()){
            int qs = q.size();
            for (int s=0 ; s<qs ; s++){
                point cur = q.front();
                q.pop();
                if (flower[cur.r][cur.c]) continue; // cur가 꽃이 있는 자리인 경우 퍼질 좌표를 구하지 않는다.
                for (int d=0 ; d<4 ; d++){
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];
                    if (isRange(nr, nc) && map[nr][nc]!=0 && visit_time[nr][nc][cur.isGreen]==-1 && (visit_time[nr][nc][!cur.isGreen]==-1 || visit_time[nr][nc][!cur.isGreen]==time)){
                        visit_time[nr][nc][cur.isGreen] = time;
                        if (visit_time[nr][nc][0] == visit_time[nr][nc][1]) flower[nr][nc] = true;
                        q.push({nr, nc, cur.isGreen});
                    }
                }
            }
            time++;
        }
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (visit_time[i][j][0] == -1) continue;
                if (visit_time[i][j][0] == visit_time[i][j][1]) temp++;
            }
        }
        // cout<<"-----------------\n";
        // for (int i=0 ; i<ls ; i++) cout<<choose[i];
        // cout<<": "<<temp<<"\n";
        // cout<<"GREEN(1)\n";
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         cout<<visit_time[i][j][true]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"RED(2)\n";
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         cout<<visit_time[i][j][false]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (temp>answer) answer = temp;
        
    } while (next_permutation(choose.begin(), choose.end()));

    cout<<answer;
    return 0;
}