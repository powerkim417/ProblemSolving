#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, bool> visited;

struct state {
    int num;
    int cnt;
};

int bfs(int a, int b){
    queue<state> q;
    q.push({a, 1});
    visited[a] = true;
    while (!q.empty()){
        state cur = q.front();
        q.pop();
        if (cur.num == b) return cur.cnt;
        // 다음 값이 b보다 커지면 안됨
        if (2*cur.num <= b){
            q.push({2*cur.num, cur.cnt+1});
            visited[2*cur.num] = true;
        }
        if (10LL*cur.num+1 <= b){
            q.push({(int)(10LL*cur.num+1), cur.cnt+1});
            visited[(int)(10LL*cur.num+1)] = true;
        }
    }
    return -1;
}


// a->b를 BFS로 구현
// visited 자료구조를 map으로 사용
int main(void){
    int a,b;
    cin>>a>>b;
    cout<<bfs(a, b);
    return 0;
}