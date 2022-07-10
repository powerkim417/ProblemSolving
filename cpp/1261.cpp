#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INF 10000+1

using namespace std;

int m, n;
char map[100][100];
int dist[100][100]; // 시작점부터 (i, j)까지 최소비용 
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
typedef pair<int, int> point;
typedef pair<int, point> edge;

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dijkstra(int si, int sj){
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, {si, sj}});
    dist[si][sj] = 0;
    while (!pq.empty()){
        edge cur = pq.top();
        pq.pop();
        int curi = cur.second.first;
        int curj = cur.second.second;
        if (cur.first > dist[curi][curj]) continue;

        // 왔던 방향으로 다시 돌아가는 경우는 같거나 손해이므로 if 조건문을 만족하지 못해서 연산의 과부하를 불러오지 않음. 즉 따로 처리해줄 필요 없음
        for (int d=0 ; d<4 ; d++){
            int ni = curi+dr[d];
            int nj = curj+dc[d];
            if (isRange(ni, nj) && (dist[curi][curj]+(int)(map[ni][nj]=='1') < dist[ni][nj])){
                dist[ni][nj] = dist[curi][curj]+(int)(map[ni][nj]=='1');
                pq.push({dist[ni][nj], {ni, nj}});
            }
        }
    }
}

int main(void){
    cin>>m>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            dist[i][j] = INF;
        }
    }
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<(int)(map[i][j]=='1');
    //     }
    //     cout<<"\n";
    // }
    dijkstra(0, 0);
    cout<<dist[n-1][m-1];
    return 0;
}