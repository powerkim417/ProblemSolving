#include <iostream>

using namespace std;

int main(void){
    // 문제에서 출력하는 값은 버블소트에서 몇번째 세트만에 정렬이 완료되는지.
    int n;
    cin>>n;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a[n+1];
    for (int i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    int cnt = 0;
    for (int i=2 ; i<=n ; i++){
        if (a[i-1]>a[i]) cnt++;
    }
    cnt++;
    cout<<cnt;
}