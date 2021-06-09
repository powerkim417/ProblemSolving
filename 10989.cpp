#include <iostream>

using namespace std;

/*
이건 사실 정렬 문제가 아님
천만개의 수와 시간제한 3초와 메모리제한 8MB로 유추해야 함
수가 10000 이하의 자연수 이므로 배열에서 카운팅하고 출력하는 트릭 문제
*/

int cnt[10001] = {};

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        cnt[temp]++;
    }
    for (int i=1 ; i<=10000 ; i++){
        for (int j=0 ; j<cnt[i] ; j++){
            cout<<i<<"\n";
        }
    }
    return 0;
}