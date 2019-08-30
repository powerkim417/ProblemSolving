#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[101];
vector<int> adj[101];
int chon[101];
queue<int> q;

int bfs(int x){
    q.push(x);
    visited[x] = true;
    int cur;
    int q_size;
    int level = 0;
    while (!q.empty()){
        q_size = q.size(); 
        for (int i=0 ; i<q_size ; i++){
            cur = q.front();
            q.pop();
            chon[cur] = level;
            for (int next: adj[cur]){
                if (!visited[next]){
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        level++;
    }
}

int main(void){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int m;
    cin>>m;
    int x,y;
    for (int i=0 ; i<m ; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        // 부모 자식 순서는 별로 상관 없음
    }
    for (int i=1; i<=100 ; i++){
        chon[i] = -1; // bfs로 닿지 못하면 -1 출력
    }
    bfs(a); // a를 기준으로 b와 떨어진 거리 계산
    cout<<chon[b];
}