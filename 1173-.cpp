#include <iostream>

using namespace std;

int main(void){
    int N, m, M, T, R;
    cin>>N>>m>>M>>T>>R;
    int cnt = 0;
    int cur = m;
    int time = 0;
    // 최대 맥박까지 운동을 하고, 다음 운동 가능까지 휴식, 다시 운동하는 식으로
    while (1){
        time++;
        if (cur+T <= M){ // 운동 가능
            cnt += (M-cur)/T;
            cur += (M-cur)/T * T;
            cout<<"TIME "<<time<<": Train -> "<<cur<<" (Count "<<cnt<<")\n";
        }
        else { // 운동 불가 -> 휴식
            cur -= R;
            if (cur<m) cur = m;
            // cout<<"TIME "<<time<<": Rest -> "<<cur<<"\n";
        }
        if (cnt>=N) break;
    }
    cout<<time;
}