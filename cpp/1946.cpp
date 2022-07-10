#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin>>T;
    for (int t=0 ; t<T ; t++){
        int N; cin>>N;
        vector<pair<int, int>> v;
        int a, b;
        for (int i=0 ; i<N ; i++){
            cin>>a>>b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        int interview_max = 100001;
        // 정렬이 된 상태기 때문에 서류성적은 무조건 늦게 나오는 사원이 더 열위. 따라서 늦게 나오는 사원은 면접 성적이 더 좋아야 함
        // 중간중간 면접 순위가 더 높은 사람의 순위를 갱신해줘야 함. 중간에 나온 이 사람보다 면접이 낮은 사람을 걸러야 하므로
        for (auto p: v){
            if (p.second < interview_max) {
                cnt++;
                interview_max = p.second;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}