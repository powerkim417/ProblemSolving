/*
<N과 M(9)>
N개의 서로 같을 수 있는 숫자를 입력으로 받음
수열 내 노드 중복 활용 X
사전 순으로

N과 M(5) 참조
*/

// 인덱스는 중복되면 안되는데, 숫자는 중복되어도 되는 것을 해결해야 함
// ex) 9가 두번 있을 때 1 9 9 와 같은 것이 되어야 하나, 그 9는 각각 다른 인덱스여야 함

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
bool visited[10001]; // 인덱스는 num에 저장되는 숫자의 인덱스이다! num에 저장되는 숫자가 아님

void dfs(int cur_idx, int len, vector<int> v){
    // v는 아직 cur가 들어가기 전
    v.push_back(cur_idx);
    if (len == m) { // 원하는 갯수만큼 다 돌음
        cout<<num[v[0]];
        for (int i=1 ; i<len ; i++){
            cout<<" "<<num[v[i]];
        }
        cout<<"\n";
        return;
    }
    visited[cur_idx] = true;
    for (int next_idx=0 ; next_idx<n ; next_idx++){
        if (!visited[next_idx]){
            dfs(next_idx, len+1, v);
        }
    }
    v.pop_back();
    visited[cur_idx] = false;
}

int main(void){
    cin>>n>>m;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    vector<int> v; // num의 인덱스를 저장
    for (int i=0 ; i<n ; i++){
        v.clear();
        // 숫자로 직접 dfs를 도는 것이 아니고
        // 노드 번호로 dfs를 돌도록 함
        dfs(i, 1, v);
    }
}