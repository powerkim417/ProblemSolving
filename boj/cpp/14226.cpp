#include <iostream>
#include <queue>

using namespace std;

struct state {
    int len;
    int copy;
};

int s;

queue<state> q;
bool visited[1998+1][999+1] = {}; // len, copy
/* 999까지는 2배를 해서 1998이 될 수 있다.
구하는 답이 최대 1000이므로 1000 이상에서는 굳이 2배를 할 일이 없다.
*/

int bfs(int l, int c){
    q.push({l, 0});
    visited[l][0] = true;
    int ret = 0;
    while (!q.empty()){
        // cout<<"---"<<ret<<" second(s) elapsed---\n";
        int q_size = q.size();
        while (q_size--){
            state cur = q.front();
            // cout<<cur.len<<" "<<cur.copy<<"\n";
            if (cur.len == s) return ret;
            q.pop();
            // 1. 복사
            if (!visited[cur.len][cur.len]) {
                visited[cur.len][cur.len] = true;
                q.push({cur.len, cur.len});
            }
            // 2. 붙여넣기(1998을 넘어가는 풀이는 무의미하다고 가정)
            if (cur.copy != 0 && cur.len+cur.copy<=1998 && !visited[cur.len+cur.copy][cur.copy]) {
                visited[cur.len+cur.copy][cur.copy] = true;
                q.push({cur.len+cur.copy, cur.copy});
            }
            // 3. 삭제
            if (cur.len>=1 && !visited[cur.len-1][cur.copy]) {
                visited[cur.len-1][cur.copy] = true;
                q.push({cur.len-1, cur.copy});
            }
        }
        ret++;
    }
}

int main(void){
    cin>>s;
    cout<<bfs(1, 0);
}