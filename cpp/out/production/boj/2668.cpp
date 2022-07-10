#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nn[101];
bool visited[101];
vector<int> answer;

void dfs(int cur, int start){
    // start를 받는 이유
    // i=1~n까지 n개의 loop동안 각각 시작 비교대상이 i일 때만에 대해서 체크하기 위해!
    // i=1일 때 1->3->1로 1을 체크하지만,
    // i=2일 때 2->1->3->1이 되면서 1을 또 체크하게 되는데, start 인자를 같이 가져가면 중복 체크를 피할 수 있음

    // 이렇게 하거나, 그냥 set나 중복처리 자료구조에 담아도 되는데 이 방법이 처음이라 그냥 이렇게 짜봄
    if (visited[cur]) {
        if (cur!=start) return;
        answer.push_back(cur);
    }
    else {
        visited[cur] = true;
        dfs(nn[cur], start);
    }
}

// 사이클에 속한 원소들을 모두 출력
int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++) cin>>nn[i];

    for (int i=1; i<=n ; i++){
        for (int j=1 ; j<=n ; j++) visited[j] = false;
        dfs(i, i);
    }

    cout<<answer.size()<<"\n";
    sort(answer.begin(), answer.end());
    for (int a: answer){
        cout<<a<<"\n";
    }
    return 0;
}