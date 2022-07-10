#include <iostream>

using namespace std;

int interview[100001] = {}; // 서류 등수 i등의 면접 등수

// vector로 받고 정렬하는게 아닌 아예 서류 등수로 배열에 넣으면 정렬에 필요한 시간 소모가 없어짐
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T; cin>>T;
    for (int t=0 ; t<T ; t++){
        int N; cin>>N;
        int a, b;
        for (int i=0 ; i<N ; i++){
            cin>>a>>b;
            interview[a] = b;
        }
        int cnt = 0;
        int interview_max = 100001;
        // 정렬이 된 상태기 때문에 서류성적은 무조건 늦게 나오는 사원이 더 열위. 따라서 늦게 나오는 사원은 면접 성적이 더 좋아야 함
        // 중간중간 면접 순위가 더 높은 사람의 순위를 갱신해줘야 함. 중간에 나온 이 사람보다 면접이 낮은 사람을 걸러야 하므로
        for (int i=1 ; i<=N ; i++){
            if (interview[i] < interview_max) {
                cnt++;
                interview_max = interview[i];
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}