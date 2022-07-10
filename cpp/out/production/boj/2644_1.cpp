#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[101];
bool visited[101] = {};
queue<int> q;
int chon = 0;
int a, b;

int bfs(){
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"---"<<chon<<" chon---\n";
        for (int s=0 ; s<q_size ; s++){            
            int cur = q.front();
            // cout<<cur<<"\n";
            if (cur == b) return chon;
            q.pop();
            for (int next: adj[cur]){
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        chon++;
    }
    return -1; // 관계를 못찾았을 때
}

int main(void){
    int n;
    cin>>n;
    cin>>a>>b;
    int m;
    cin>>m;
    for (int i=0 ; i<m ; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // a에서 출발, b로 도착
    q.push(a);
    visited[a] = true;
    cout<<bfs();
}