#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;

typedef pair<int, int> P;

vector<P> adj[10001];
bool visited[10001] = {};

int prim(int V){
    int ret = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1}); // 1번 노드에서 시작
    for (int loop=0 ; loop<V ; loop++){
        P cur = {INF, -1};
        while (!pq.empty()){
            cur = pq.top();
            if (visited[cur.second]) pq.pop();
            else break;
        }
        if (cur.first == INF) return INF;
        ret += cur.first;
        visited[cur.second] = true;
        for (P next: adj[cur.second]) pq.push(next);
    }
    return ret;
}

// 임의의 두 정점 사이에 경로가 있다 => 연결 그래프 보장
// MST 기본 예제 - prim(프림)
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E; cin>>V>>E;
    int a, b, c;
    for (int i=0 ; i<E ; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int answer = prim(V);
    cout<<answer;
    return 0;
}