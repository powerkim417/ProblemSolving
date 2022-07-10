#include <iostream>

using namespace std;

int d, n;
int len[300001], pizza[300001];

// 이중포문으로는 O(nd) 이기 때문에 시간 초과가 난다.
/*
<구현>

1. 오븐의 특정 위치의 지름이 자신의 위보다 긴 것은 의미가 없다.
즉, 위의 지름이 3이라면 아래의 지름이 5든 7이든 3까지밖에 안들어가기 때문.
따라서, 들쑥날쑥한 오븐의 지름을 문제 해결에 용이하게 조금 바꿀 수 있다!!!!!
ex)
5    5
6    5
4    4
3 -> 3
6    3
2    2
3    2

2. 피자를 순서대로 이분탐색 넣어도 되지만,
높이 D에서부터 1까지 올리면서 쌓아도 된다.
(수정)while보다는 for문 하나가 더 깔끔할수도...
*/

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>d>>n;
    for (int i=1 ; i<=d ; i++){
        cin>>len[i];
        if (i>1 && len[i]>len[i-1]) len[i] = len[i-1];
    }
    for (int i=1 ; i<=n ; i++){
        cin>>pizza[i];
    }
    // 투 포인터
    int cur_p=1;
    for (int cur_l=d ; cur_l>0 ; cur_l--){
        if (pizza[cur_p]>len[cur_l]) continue; // 안들어가는 경우 올라감
        // 가장 아래 위치부터 탐색이므로 피자가 들어가는 경우 이 위치로 자리잡는다.(cur_p는 cur_l 위치에!)
        // cout<<"Pizza "<<cur_p<<" placed in "<<cur_l<<"\n";
        cur_p++;
        if (cur_p>n){ // 피자 끝. 현 위치 출력
            cout<<cur_l;
            return 0;
        }
    }
    // 오븐의 마지막까지 다 봤는데 피자를 다 못넣은 경우(cur_l == 0)
    cout<<"0";
    return 0;
}