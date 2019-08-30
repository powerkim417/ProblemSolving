#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[10000]; // index: i*n+j
queue<int> q;
int n,m;
char map[100][100];
int dist[10000];
int adjr[4] = {-1, 0, 1, 0};
int adjc[4] = {0, 1, 0, -1};

// /m %m 보다 struct 좌표 쓰는게 더 시간이 빠름!!
void bfs(int x){
    visited[x] = true;
    q.push(x);
    int level = 0;
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"---level "<<level<<"---"<<endl;
        for (int i=0 ; i<q_size ; i++){
            // 포문이 하나 더 생겼다고 더 깊어지는게 아니고,
            // 해당 레벨의 노드 수만큼을 돌고 난 뒤
            // level++ 을 하여 노드의 레벨을 구분하기 위함.
            // 해당 레벨 노드 수만큼을 다 돌고 나면
            // 그 다음 레벨 노드들만이 저장되어 있어
            // 또 다시 q_size를 계산하고 나면
            // 다음 레벨 노드 수만큼을 돌게 되어
            // 노드의 레벨이 구분되는 것을 확인할 수 있다.
            int cur = q.front();
            q.pop();
            dist[cur] = level;
            // cout<<cur<<endl;
            for (int j=0 ; j<4 ; j++){
                int nextr = cur/m + adjr[j];
                int nextc = cur%m + adjc[j];
                int next = nextr*m + nextc;
                if (nextr>=0 && nextr<n
                && nextc>=0 && nextc<m
                && map[nextr][nextc]=='1'
                && !visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level++;
    }
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    bfs(0);
    cout<<dist[n*m-1] + 1<<endl;
}