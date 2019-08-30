#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int cnt;
    // cnt = n - (가장 큰 약수)
    // 2로 나눠보고, 나눠지면 나눠진 수가 가장 큰 약수
    // 아니면 3으로 나눠보고, ...
    // sqrt(n) 까지 나눠본다.
    int maxdiv = 1;
    for (int i=2 ; i*i<=n ; i++){
        // 원래는 소수만 i로 써야 이상적인 시간 복잡도지만
        // 전부다 해도 10^6의 시간이 걸리므로..
        if (n%i==0) {
            maxdiv = n/i;
            break;
        }
    }
    cnt = n - maxdiv;
    cout<<cnt;
}