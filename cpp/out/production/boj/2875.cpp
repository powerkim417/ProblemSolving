#include <iostream>

using namespace std;

int main(void){
    int n,m,k;
    cin>>n>>m>>k; // n명 여자 m명 남자 k명 인턴
    int max = (n/2 < m) ? n/2 : m; // 최대 팀
    int r_n = n - 2*max; // 남은 여자
    int r_m = m - max; // 남은 남자
    while (r_n + r_m < k){
        r_n += 2;
        r_m += 1;
        max -= 1;
    }
    cout<<max;
}