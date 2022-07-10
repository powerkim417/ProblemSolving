#include <iostream>

using namespace std;

int N, S;
int sum[100000];
int psum(int s, int e){
    if (s==0) return sum[e];
    else return (sum[e]-sum[s-1]);
}

int main(void){
    cin>>N>>S;
    for (int i=0 ; i<N ; i++){
        cin>>sum[i];
        if (i!=0) sum[i] += sum[i-1];
    }
    // 각 시작점에서, 몇번 더하면 초과되는지를 확인
    //    n        *    log n(binary search)
    int L, R, M;
    int min_idx = N+1, idx;
    for (int i=0 ; i<N ; i++){
        if (psum(i, N-1) < S) continue;
        L = i, R = N-1;
        while (L<=R){
            M = (L+R+1)/2; // 중간값이 2개일 때 오른쪽 값을 택함
            if (psum(i, M)<S) L = M+1;
            else if (psum(i, M)>S) R = M-1;
            else if (psum(i, M)==S) break;
        }
        idx = (L+R+1)/2 + 1 - i;
        if (min_idx > idx) {
            min_idx = idx;
            // cout<<i<<" "<<idx<<endl;
        }
    }
    if (min_idx == N+1) cout<<"0";
    else cout<<min_idx;
}