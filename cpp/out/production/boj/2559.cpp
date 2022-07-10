#include <iostream>

using namespace std;

int num[100000];

// 슬라이딩 윈도우

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0 ; i<n ; i++){
        cin>>num[i];
    }
    int answer, sum = 0;
    for (int i=0 ; i<k ; i++){
        sum += num[i];
    }
    answer = sum;
    // sum 초기값 설정 완료 (0~k-1)
    for (int i=1 ; i+k-1<n ; i++){
        sum = sum-num[i-1]+num[i+k-1];
        // cout<<sum<<"\n";
        if (sum>answer) answer = sum;
    }
    cout<<answer;
    return 0;
}