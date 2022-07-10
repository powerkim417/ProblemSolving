#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001] = {};
queue<int> q;

int bfs(int start){
    int time = 0;
    q.push(start);
    visited[start] = true;
    if (start==K) return 0;
    while (!q.empty()){
        int q_size = q.size();
        while (q_size--){
            int cur = q.front();
            q.pop();
            if (cur-1>=0 && !visited[cur-1]) {
                if (cur-1==K) return time+1;
                q.push(cur-1);
                visited[cur-1] = true;
            }
            if (cur+1<=100000 && !visited[cur+1]) {
                if (cur+1==K) return time+1;
                q.push(cur+1);
                visited[cur+1] = true;
            }
            if (cur*2<=100000 && !visited[cur*2]) {
                if (cur*2==K) return time+1;
                q.push(cur*2);
                visited[cur*2] = true;
            }
        }
        time++;
    }
}

int main(void){
    cin>>N>>K;
    cout<<bfs(N);
}