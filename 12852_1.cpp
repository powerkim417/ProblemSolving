#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001] = {};
int nxt[1000001];

int bfs(int n){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int answer = 0;
    while (!q.empty()){
        int q_size = q.size();
        while (q_size--){
            int cur = q.front();
            if (cur == n) return answer;
            q.pop();
            if (3*cur <= 1000000 && !visited[3*cur]){
                q.push(3*cur);
                visited[3*cur] = true;
                nxt[3*cur] = cur;
            }
            if (2*cur <= 1000000 && !visited[2*cur]){
                q.push(2*cur);
                visited[2*cur] = true;
                nxt[2*cur] = cur;
            }
            if (cur+1 <= 1000000 && !visited[cur+1]){
                q.push(cur+1);
                visited[cur+1] = true;
                nxt[cur+1] = cur;
            }
        }
        answer++;
    }
}

// BFS
// 1에서 갈 수 있는 노드들을 뻗어나가면서 n에 도착
int main(void){
    int n;
    cin>>n;
    cout<<bfs(n)<<"\n";
    cout<<n;
    while (n != 1){
        n = nxt[n];
        cout<<" "<<n;
    }
}