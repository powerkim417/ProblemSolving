#include <iostream>
#include <stack>

using namespace std;

struct state {
    int num;
    int height;
};

int h[100001];
int cnt[100001] = {};
state cand[100001];
stack<state> s;

// 스택 활용 문제
// 자기보다 높은 모든 건물을 다 담지 말고, 현재 스택에 있는 모든 건물들이 자기보다 큰 건물이라고 그 갯수를 더하면 됨
// 더 가까운 건물의 경우 왼쪽, 오른쪽 하나씩만 구해서 나중에 비교
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>h[i];
        cand[i] = {-1, -1};
    }
    // 오른쪽에서 왼쪽 건물 보이는지
    for (int i=1 ; i<=n ; i++){
        if (!s.empty()){
            while (!s.empty() && s.top().height <= h[i]) s.pop();
            // stack에는 i번째 건물보다 높은 건물들만 들어있도록 유지
            cnt[i] += s.size();
            if (!s.empty()) cand[i] = s.top();
        }
        s.push({i, h[i]});
    }

    while (!s.empty()) s.pop();

    // for (int i=1 ; i<=n ; i++){
    //     cout<<cnt[i];
    //     if (cnt[i]!=0) cout<<" "<<cand[i].num;
    //     cout<<"\n";
    // }
    // cout<<"---------\n";

    // 왼쪽에서 오른쪽 건물 보이는지
    for (int i=n ; i>=1 ; i--){
        if (!s.empty()){
            while (!s.empty() && s.top().height <= h[i]) s.pop();
            // stack에는 i번째 건물보다 높은 건물들만 들어있도록 유지
            cnt[i] += s.size();
            // 현재 stack에 들어있는 건물들은 i보다 오른쪽 건물들
            // 즉, cand가 갱신되려면 거리차이가 같으면 안되고 아예 더 작아야 함
            if (!s.empty() && (cand[i].height==-1 || s.top().num-i < i-cand[i].num)) cand[i] = s.top();
        }
        s.push({i, h[i]});
    }

    for (int i=1 ; i<=n ; i++){
        cout<<cnt[i];
        if (cnt[i]!=0) cout<<" "<<cand[i].num;
        cout<<"\n";
    }
    return 0;
}