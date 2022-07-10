/*
<N과 M(7)>
N개의 서로 다른 숫자를 입력으로 받음
수열 내 숫자 중복 활용 O
사전 순으로

N과 M(3) 참조
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num;
// bool visited[10001];

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
    for (int next=0 ; next<n ; next++){
        // if (!visited[num[next]]){
            dfs(num[next], len+1, v);
        // }
    }
    v.pop_back();
    // visited[cur] = false;
}

int main(void){
    cin>>n>>m;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    vector<int> v;
    for (int i=0 ; i<n ; i++){
        v.clear();
        dfs(num[i], 1, v);
    }
}