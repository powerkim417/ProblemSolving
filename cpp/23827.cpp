#include <iostream>

using namespace std;

// {S*S - (a1*a1 + a2*a2 + ... + an*an)}/2 로 접근하면 S가 최대 25*10^10까지 나와서 S*S는 10^20을 넘겨버림.
// n=4일 경우 a(b+c+d) + b(c+d) + c(d) 이므로 부분합으로 접근!
// 근데 위처럼 계산할거면 순회를 두번 해야 하니
// b(a) + c(a+b) + d(a+b+c) 로 생각하면 더 편할듯

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    long long answer = 0, sum = 0;
    int cur;
    for (int i=0 ; i<n ; i++){
        cin>>cur;
        answer += cur*sum;
        sum += cur;
        answer %= 1000000007;
        sum %= 1000000007;
    }
    cout<<answer;
    return 0;
}