#include <iostream>

using namespace std;

int main(void){
    int n, m;
    int a[50], b[50];
    cin>>n>>m;
    for (int i=0 ; i<n ; i++) cin>>a[i];
    for (int i=0 ; i<m ; i++) cin>>b[i];
    int rem = 0;
    int curbook = 0;
    int curbox = 0;
    while (curbox < n && curbook < m){
        // a가 박스고 b가 책
        if (b[curbook] > a[curbox]){ // 3번으로 간다
            rem += a[curbox]; // 남은 용량 추가
            curbox++; // 다음 박스를 가져오고
            // 책은 그대로
        }
        else { // 2번으로 간다
            a[curbox] -= b[curbook]; // 현재 책을 현재 박스에 넣음
            curbook++; // 다음 책으로 간다
        }
    }
    // 박스를 다 보고 책이 남은 경우는 더 고려할 필요 없고,
    for ( ; curbox<n ; curbox++){ // 책을 다 보고 박스가 남은 경우는 빈 박스들의 용량을 다 합해야 함
        rem += a[curbox];
    }
    cout<<rem;
    return 0;
}