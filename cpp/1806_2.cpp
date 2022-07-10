#include <iostream>

using namespace std;

int sum[100001];
int partsum(int s, int e){
    // s는 1 이상만 들어간다고 가정
    return (sum[e]-sum[s-1]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin>>n>>s;
    sum[0] = 0;
    for (int i=1 ; i<=n ; i++){
        cin>>sum[i];
        sum[i] += sum[i-1];
        // cout<<sum[i]<<" ";
    }

    // 그때그때 계산하면 시간초과.
    // n * logn(이분탐색), 즉 n번 이분탐색 하게 풀어야 된다.

    // 각 시작점에서 몇번 더하면 초과되는지 체크?

    // 각 시작점에서 새로운 배열이 생기는데,
    // psum(1, 1), psum(1, 2), .., psum(1, n)
    // psum(2, 2), ..., psum(2, n)
    // 이런식으로 된 새로운 배열을 이분 탐색 하면서
    // 몇번째에서 초과가 나는지 확인하는 방식
    int L, R, M; // 몇번째 원소까지 인지
    int len;
    int answer = n+1;
    for (int i=1 ; i<=n ; i++){
        if (partsum(i, n) < s) continue; // 합이 안되는 경우는 idx가 계산되면 안되므로 이 줄은 꼭 필요!
        L=i-1;
        R=n;
        // cout<<"L: "<<L<<", R: "<<R<<" START!\n";
        while (L+1<R){
            M = (L+R) >> 1;
            if (partsum(i, M)<s){ // 오른쪽으로 더 가야함
                L = M; // 여긴 포함 X
                // cout<<"L change to "<<L<<"\n";
            }
            else { // if partsum(i,M)>s
                R = M; // 여긴 포함 O
                // cout<<"R change to "<<R<<"\n";
            }
        }
        // LR
        // XO
        len = R - i + 1;
        // 여기서 나온 M이 i에서 시작한 부분합 배열에서 최소길이가 되는 인덱스
        if (len < answer) {
            // cout<<i<<" "<<L<<" "<<R<<" "<<len<<endl;
            answer = len;
        }
    }
    if (answer == n+1) cout<<"0";
    else cout<<answer;
}