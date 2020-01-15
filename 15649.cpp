/*
<N과 M(1)>
1~N까지의 수
수열 내 숫자 중복 활용 X
사전 순으로
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[9]; // 숫자 갯수가 적어서 비트마스킹으로도 가능할듯

void dfs(int cur, int len, vector<int> v){
    // v는 아직 cur가 들어가기 전
    v.push_back(cur);
    if (len == m) { // 원하는 갯수만큼 다 돌음
        cout<<v[0];
        for (int i=1 ; i<len ; i++){
            cout<<" "<<v[i];
        }
        cout<<"\n";
        return;
    }
    visited[cur] = true;
    for (int next=1 ; next<=n ; next++){
        if (!visited[next]){
            dfs(next, len+1, v);
        }
    }
    v.pop_back();
    /*
    1 2 .. 와 같은 탐색을 하고
    2 1 와 같이 1을 다시 보려면
    앞의 탐색에서 1을 다 본 후 visited=false 처리를 해줘야 함
    (백트래킹)
    */
    visited[cur] = false;
}

int main(void){
    cin>>n>>m;
    vector<int> v;
    for (int i=1 ; i<=n ; i++){
        v.clear();
        dfs(i, 1, v);
    }
}