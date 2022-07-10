#include <iostream>

using namespace std;

int main(void){
    int N, m, M, T, R;
    cin>>N>>m>>M>>T>>R;
    int cnt = 0; // 운동 횟수
    int cur = m;
    int time = 0;

    // 운동을 N분 할 수 없는 경우는
    // 운동을 아예 할 수 없는 경우밖에 없음
    // 운동을 1분 이상 했다면 무조건 N분 할 수 있다!
    // 처음부터 m + T <= M 이어서 1분을 했을 것이고,
    // 휴식에 의해 다시 m이 되기 때문!
    if (cur+T > M){
        cout<<"-1";
        return 0;
    }
    // 최대 맥박까지 운동을 하고, 다음 운동 가능까지 휴식, 다시 운동하는 식으로
    while (1){
        time++;
        if (cur+T <= M){ // 운동 가능
            cur += T;
            cnt++;
            // cout<<"TIME "<<time<<": Train -> "<<cur<<"\n";
        }
        else { // 운동 불가 -> 휴식
            cur -= R;
            if (cur < m) cur = m;
            // cout<<"TIME "<<time<<": Rest -> "<<cur<<"\n";
        }
        if (cnt >= N) break;
    }
    cout<<time;
}