#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int n, k;

bool f(long long int x){ // O(n)
    long long int cnt = 0;
    for (int i=1 ; i<=n ; i++){
        /* i, 2i, .., ni 인데
        ni<=x 일경우 이 행에서는 +n 해야되고,
        아닐 경우 i, .., ai까지가 x 이하다. (a개 존재)
        즉 ai<=x<(a+1)i 인 a가 존재하며, 
        (x/i - 1) < a <= x/i 이므로
        a = floor(x/i) 이다.
        */
        if (n*i <= x) cnt += n;
        else cnt += x/i;
    }
    if (cnt >= k) return true;
    else return false;
}

int main(void){
    cin>>n>>k;
    /* k번째 원소는 자신보다 작은 수의 갯수가 k-1개
    f(x) = 'x보다 작거나 같은 원소의 갯수가 k개 이상'
    이라는 함수가 존재한다면
    원소들을 오름차순으로 쭉 정렬했을 때
    우리가 구하는 k번째 원소는 f(x) = true인 첫 원소가 된다.    
    */
    /*
    1 2 3 4 5
    2 4 6 8 10
    3 6 9 12 15
    4 8 12 16 20
    5 10 15 20 25
    */
    /* f(x)가 O(n)이고, 이 분포를 이진으로 탐색하므로 log n
    즉 nlogn 으로 갯수를 찾는다. */

    /* 이제 최소값을 찾아야 하는데, 배열에서 찾는게 아닌
    이제 1~n*n 에서 최소값을 찾는다.
    f(x) 함수의 경우 _- 형태로 증가하고, 처음으로 true가 되는 값이 우리가 구하는 값!
    만약 처음 true된 x가 배열에 없는 수라고 가정하면
    배열 수가 A1 A2 ... Ak B .. 순서로 정렬 되었을 때 Ak 와 B 사이에 존재하게 될 텐데,
    그러면 Ak 가 최소값으로 나왔어야 하므로 모순!
    따라서 처음으로 등장하는 x가 배열에 있다는 것을 증명할 수 있다. 

    그리고, 1~n*n에서의 최소값을 찾는 과정이 O(n*n) 인데 그러면 시간복잡도가 총 n^3이 되므로
    이를 이진탐색으로 하는 것!
    그러면 n * log(n^2) => O(nlogn) 으로 된다.
    */
    long long int L = 1, R = 1000000000;
    long long int M;
    while (L<=R){
        M = (L+R)/2;
        if (f(M) == false) L = M+1;
        else if (f(M) == true) R = M-1;
    }
    /* R<L이 되어 탈출하는 경우
    f(R+1) = true, f(L-1) = false일 텐데
    _- 형태의 함수여야 하므로 L-1 < R+1.
    즉 L < R+2 이고, R<L<R+2 이므로 L = R+1.
    즉 두 수는 1 차이가 난다.
    위 두 식을 바꾸면 f(L) = true, f(R) = false 이므로
    L이 구하는 최소값!
    */
    cout<<L;
}