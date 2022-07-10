#include <iostream>
#include <vector>

using namespace std;

vector<int> up[100001]; // i보다 위인 경우
vector<int> down[100001]; // i보다 아래인 경우
bool visited[100001][2] = {}; // j: 0 up, 1 down

int n,m,x;
int up_cnt = 0; // 윗순위 사람의 수
int down_cnt = 0; // 아래순위 사람의 수

void udfs(int cur){
    visited[cur][0] = true;
    for (int next: up[cur]){
        if (!visited[next][0]) {
            up_cnt++;
            udfs(next);
        }
    }
}
void ddfs(int cur){
    visited[cur][1] = true;
    for (int next: down[cur]){
        if (!visited[next][1]) {
            down_cnt++;
            ddfs(next);
        }
    }
}

int main(void){
    cin>>n>>m>>x;
    int a,b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        down[a].push_back(b);
        up[b].push_back(a);
    }
    udfs(x);
    ddfs(x);
    // up_cnt: 자신보다 위인 사람의 수
    // down_cnt: 자신보다 아래인 사람의 수
    cout<<(up_cnt+1)<<" "<<(n-down_cnt);
}