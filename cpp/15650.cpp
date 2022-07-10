/*
<N과 M(2)>
1~N까지의 수
오름차순 순열
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
    // N과 M(1) 코드와 비교했을 때 여기가 바뀜
    for (int next=cur+1 ; next<=n ; next++){
        if (!visited[next]){
            dfs(next, len+1, v);
        }
    }
    v.pop_back();
    /*
    백트래킹은 그대로 유지해야 함.
    대신 위의 next 조건을 바꿀 것
    이 코드를 지울 경우
    (8 4의 경우 1 2 3 4로 시작하면서 2 3 4에 대한 visited가 true로 유지되어
    모든 경우 탐색이 1로 시작하는 경우만 출력됨)
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