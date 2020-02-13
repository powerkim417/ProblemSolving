#include <iostream>

using namespace std;

long long int n, k;

/*
1 2 3 4 5 .. n
2 4 6 8 ... 2n
...
n 2n 3n ... n*n
*/
/*
1. f(x): x 이하인 수가 k개 이상 존재하면 true, 아니면 false
즉 f(x)=true가 되는 가장 작은 x가 답(K번째 수)이 된다. 

2. 원소를 하나하나 넣어서 그 중에서가 아닌 1~n*n의 모든 수 사이에서 찾는 것이 핵심이다.
f(x)=true가 되는 가장 작은 x를 찾았을 때 이 수가 배열에 있는지 확신할 수 없는데,
만약 k번째 수인 x가 배열에 없는 수라고 하면,
a_1 a_2 a_3 .. a_k a_(k+1) ... 와 같이 이어진 배열에서
x는 정의에 의해 a_k보다 크고 a_(k+1)보다 작다.
그런데 f(a_k)도 true 이므로 최소의 수는 x가 아닌 a_k로 구해져야 했으므로 모순.
따라서 k번째 수인 x는 항상 배열에 있는 수이므로 안심하고 1~n*n 사이에서 찾아도 된다.

3. 특정 수 x에 대해 f(x)를 구하는 방법
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25
i 2i 3i 4i ... ni
*/

bool f(long long x){
    long long cnt = 0;
    for (long long i=1 ; i<=n ; i++){
        if (n*i <= x) cnt += n; // 한줄 전체가 k이하인 경우
        else { // k이하인 원소가 전체가 아닌 경우.. ai <= x < (a+1)i 이고(a개 존재), x/i - 1 < a <= x/i 이므로 a = floor(x/i)
            cnt += x/i;
        }
    }
    if (cnt >= k) return true;
    else return false;
}

/* 이분탐색 코드 틀
L = min - 1
R = max + 1
while (L+1<R){
    M = (L+R)>>1;
    if (f(M)){
        R = M;
    }
    else {
        L = M;
    }
}
와 같은 형태일 때
LR
XO 이런 형태로 끝나므로 구하는 답은 R일 것
*/


int main(void){
    cin>>n>>k;
    long long L = 1-1; // 최대 범위보다 밖에 있어야 전부 볼 수 있음
    long long R = n*n+1; // 최대 범위보다 밖에 있어야 전부 볼 수 있음
    // 어차피 이 두 값은 직접 f(x)에 들어가지 않으며, M을 계산할 때만 사용하므로 넘어도 됨! 같은 간격만큼(-1, +1) 차이나야 하는건 지켜야하는듯.
    long long M;
    while (L+1<R){
        M = (L+R)/2;
        if (f(M)){
            R = M;
        }
        else {
            L = M;
        }
    }
    // LR
    // XO
    cout<<R;
}