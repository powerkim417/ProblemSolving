#include <iostream>

using namespace std;

struct belt {
    int dur;
    bool robot;
};

int n, k;
belt arr[200];
// 0: 올리는 위치, n-1: 내리는 위치
int zero;

// 이 부분은 queue로 구현하면 더 쉬울듯
void rotate(){
    belt temp = arr[2*n-1];
    for (int i=2*n-1 ; i>=1 ; i--){
        arr[i] = arr[i-1];
        if (i>=n) arr[i].robot = false; // 첫 전체회전때 내리는 경우
    }
    arr[0] = temp;
}

void robot_on(int idx){
    arr[idx].robot = true;
    arr[idx].dur--;
    if (arr[idx].dur == 0) zero++;
}

int main(void){
    cin>>n>>k;
    for (int i=0 ; i<2*n ; i++){
        cin>>arr[i].dur;
        arr[i].robot = false;
    }
    int ret = 1;
    zero = 0;
    while (1){
        ///// 1
        rotate();

        ///// 2
        // 마지막 발판에 있는 로봇의 이동
        if (arr[n-1].robot){
            arr[n-1].robot = false;
        }
        // 마지막 발판이 아닌 발판에 있는 로봇의 이동
        for (int i=n-2 ; i>=0 ; i--){
            if (!arr[i].robot) continue;
            if (!arr[i+1].robot && arr[i+1].dur > 0){
                arr[i].robot = false;
                robot_on(i+1);
            }
        }

        ///// 3
        if (!arr[0].robot && arr[0].dur > 0) {
            robot_on(0);
        }

        ///// 4
        if (zero >= k) break;
        ret++;

        // for (int i=0 ; i<2*n ; i++){
        //     cout<<((arr[i].robot)?"V":" ")<<" ";
        // }
        // cout<<"\n";
        // for (int i=0 ; i<2*n ; i++){
        //     cout<<arr[i].dur<<" ";
        // }
        // cout<<"\n";
    }
    cout<<ret;
    return 0;
}