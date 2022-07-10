#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int INF = 140616 + 1;
// N=125이고 전부 w=9일 때 지그재그로 한다고 치면
// 124*9 + 9 + 124*9 + ... + 9 + 124*9
// = 124*9*125 + 9*124 = 140616

typedef pair<int, int> point;
typedef pair<int, point> edge;
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

// 다익스트라 + 좌표계

int main(void){
    int n;
    for (int t=1 ; ; t++){
        cin>>n;
        if (n==0) break;
        cout<<"Problem "<<t<<": ";
        int map[n][n];
        int cost[n][n];
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                cin>>map[i][j];
                cost[i][j] = INF;
            }
        }
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        pq.push({map[0][0], {0,0}}); // 시작점
        while (!pq.empty()){
            int cur_cost = pq.top().first;
            point cur = pq.top().second;
            pq.pop();

            if (cur_cost > cost[cur.first][cur.second]) continue;

            cost[cur.first][cur.second] = cur_cost;

            for (int i=0 ; i<4 ; i++){
                int next_r = cur.first + r[i];
                int next_c = cur.second + c[i];
                if (next_r < 0 || next_r >= n
                || next_c < 0 || next_c >= n) continue;
                if (cur_cost + map[next_r][next_c] < cost[next_r][next_c]){
                    pq.push({cur_cost + map[next_r][next_c], {next_r, next_c}});
                    cost[next_r][next_c] = cur_cost + map[next_r][next_c];
                }
            }
        }
        cout<<cost[n-1][n-1]<<"\n";
    }
}