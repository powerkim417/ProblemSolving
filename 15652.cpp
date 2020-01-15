/*
<N과 M(4)>
1~N까지의 수
비내림차순 순열
수열 내 숫자 중복 활용 O
사전 순으로
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
/*
방문한 노드를 재방문해야 하므로
N과 M(1) 코드와 비교했을 때
visited 관련 코드가 모두 사라짐. 
*/ 
// bool visited[9];

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
    // visited[cur] = true;
    
    // N과 M(3) 코드와 비교했을 때 여기가 바뀜
    for (int next=cur ; next<=n ; next++){
        // if (!visited[next]){
            dfs(next, len+1, v);
        // }
    }
    v.pop_back();
    // visited[cur] = false;
}

int main(void){
    cin>>n>>m;
    vector<int> v;
    for (int i=1 ; i<=n ; i++){
        v.clear();
        dfs(i, 1, v);
    }
}