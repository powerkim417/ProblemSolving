#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d;

bool visited[1000001] = {};
queue<int> q;
int dist = 1;

void bfs(){
    q.push(s);
    visited[s] = true;
    while (!q.empty()){
        int q_size = q.size();
        for (int i=0 ; i<q_size ; i++){     
            int cur = q.front();
            q.pop();
            if (cur+u<=f && !visited[cur+u]) {
                q.push(cur+u);
                visited[cur+u] = true;
                if (cur+u == g){
                    cout<<dist;
                    return;
                }
            }
            if (cur-d>=1 && !visited[cur-d]) {
                q.push(cur-d);
                visited[cur-d] = true;
                if (cur-d == g){
                    cout<<dist;
                    return;
                }
            }
        }
        dist++;
    }
    cout<<"use the stairs";
}

int main(void){
    cin>>f>>s>>g>>u>>d;
    // 총 1층부터 F층까지
    // S층에서 G층으로
    // +U 또는 -D
    if (s==g) cout<<"0"; // 처음 제출에서 틀린 이유. s==g일 때는 bfs가 아무리 돌아가도 못잡게 짜놨으므로 예외처리 할 것
    else bfs();
}