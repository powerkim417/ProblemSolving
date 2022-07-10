#include <iostream>
#include <algorithm>

using namespace std;

vector<int> x;

int main(void){
    int n;
    cin>>n;
    int s, a;
    for (int i=0 ; i<n ; i++){
        cin>>s>>a;
        x.push_back(s-a);
    }
    sort(x.begin(), x.end());
    // 문제 글이 복잡한 것에 비해 task는 다소 명확했던 편
    // sum(abs(x[i] + T))가 최소인 T의 갯수
    /* x를 정렬하면
    |T-10| + |T-1| + |T+1| + |T+2| + |T+3| 처럼 나올텐데,
    절대값 식의 합 함수 그래프를 생각하면
    n이 홀수라면 최솟값이 표족. T는 중앙값을 0으로 만드는 하나의 값만이 답이고,
    n이 짝수라면 최솟값이 가로선분 형태. T는 x[n/2-1] ~ x[n/2] 사이의 모든 값이 답이 된다.
    */
    if (n%2==1) cout<<"1";
    else cout<<x[n/2]-x[n/2-1]+1;
    return 0;
}