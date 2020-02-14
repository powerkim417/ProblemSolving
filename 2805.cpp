#include <iostream>

using namespace std;

int n, m;
int tree[1000000];

/*
f(x): 절단기 높이가 x일 때 m미터 이상을 얻을 수 있는지(BOOL)
----
    ---- 형태의 그래프가 될 것이다.
이 때 f(x) = true인 가장 큰 x를 구해야 함
*/
bool f(int x){
    long long int chopped = 0;
    for (int i=0 ; i<n ; i++){
        if (tree[i]-x>0) {
            chopped += (tree[i]-x);
        }
    }
    if (chopped >= m) return true;
    else return false;
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++) cin>>tree[i];
    // 절단기 설정하는 높이를 이분탐색
    int L = 0;
    int R = 1000000000+1;
    int M;
    while (L+1<R){
        // cout<<L<<" "<<R<<"\n";
        M = (L+R)>>1;
        if (f(M)) L = M; // L에는 답이 있을 수 있음
        else R = M; // R에는 답이 있을 수 없음 -> 이래서 +1로 시작해도 되는듯?
    }
    // LR
    // OX
    cout<<L;
    return 0;
}