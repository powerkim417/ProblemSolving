#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visited[100001] = {};

queue<int> q;

int cnt = 0;
bool found = false;

/* 이번 풀이의 핵심은
다음 노드를 queue에 넣을 때 방문 체크를 하여 중복 방지를 하는 것이 아니라
동시에 도달하는 경우의 수를 찾기 위해 중복된 queue push를 허용하고, cur로 읽어올 때 방문 체크를 하도록 한다.
*/

int bfs(){
    visited[n] = true;
    q.push(n);
    int time = 0;
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"===="<<time<<"====\n";
        while (q_size--){
            int cur = q.front();
            visited[cur] = true; // 방문체크를 여기서 한다!!!!!!!!!!!
            // cout<<cur<<"\n";
            if (cur==k) { // 가장 빠른 시간에 찾았으면 같은 시간에 몇번 더 있는지 세어야 함
                found = true;
                cnt++;
            }
            q.pop();
            if (cur-1>=0 && !visited[cur-1]) {
                // visited[cur-1] = true;
                q.push(cur-1);
            }
            if (cur-1<=100000 && !visited[cur+1]) {
                // visited[cur+1] = true;
                q.push(cur+1);
            }
            if (2*cur<=100000 && !visited[2*cur]) {
                // visited[2*cur] = true;
                q.push(2*cur);
            }
        }
        if (found) return time;
        time++;
    }
}

int main(void){
    cin>>n>>k;
    cout<<bfs()<<"\n";
    cout<<cnt;
    return 0;
}