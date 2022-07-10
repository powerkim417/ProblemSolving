#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int child;
    int weight;
};

int n;
bool visited[10001];
vector<edge> adj[10001];
queue<edge> q;
int max_cost;

/*
앞의 풀이에서 bfs를 올바르게 사용하지 않은 것 같아서
새로 풀은 풀이!!
cost를 일일히 저장하지 않고
특정 점에서 가장 멀리 떨어진 점을 구하는 방식으로 구함
*/


int bfs(int start){ // start에서 가장 먼 점을 출력
    for (int i=1 ; i<=n ; i++){
        visited[i] = false;
    }
    q.push({start, 0});
    visited[start] = true;
    int farest = start;
    int farest_cost = 0;
    while (!q.empty()){
        int cur = q.front().child;
        int cur_cost = q.front().weight;
        q.pop();
        for (edge next: adj[cur]){
            if (!visited[next.child]){
                q.push({next.child, cur_cost+next.weight});
                // 이전 점부터 해당 점까지의 weight가 아니라
                // 해당 점까지 걸리는 거리를 넣는다!!!!!!!!!!!
                visited[next.child] = true;
                if (farest_cost < cur_cost+next.weight){
                    farest_cost = cur_cost+next.weight;
                    farest = next.child;
                }
            }
        }
    }
    max_cost = farest_cost;
    return farest;
}

/* 트리의 지름 알고리즘

임의의 점에서 가장 멀리 떨어진 점,
그리고 그 점에서 가장 멀리 떨어진 점
이 두 점 사이의 거리가 지름이다. */

int main(void){
    cin>>n;
    int p,c,w;
    for (int t=0 ; t<n-1 ; t++){
        cin>>p>>c>>w;
        adj[p].push_back({c,w});
        adj[c].push_back({p,w});
    }
    
    int far1 = bfs(1);
    int far2 = bfs(far1);
    // cout<<far1<<" "<<far2<<endl;
    cout<<max_cost;
}