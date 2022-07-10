#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
vector<long long> num;

/* 풀이 1. O(n^2logn)
2중포문 + 이분탐색
*/

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end()); // 오름차순
    // a+b 를 먼저 전부 구하고 (O(n^2))
    // -(a+b)와 가장 비슷한 값을 골라 c로 사용(이분탐색 log n)
    // 그러면 전체 시간복잡도는 O(n^2logn)

    long tempa, tempb, tempc;
    long long min = 1000000000LL+999999999LL+999999998LL;
    long a=0, b=0, c=0; // 답으로 출력할 세 용액
    // 세 용액을 각각 i,j,k(i<j<k)라고 하고 탐색
    for (int i=0 ; i<n-2 ; i++){ // i,j,k 모두 서로 다르게 존재해야 하므로 i는 n-2 미만, j는 n-1 미만이라는 추가 조건이 존재해야 k가 온전히 존재할 수 있음
        for (int j=i+1 ; j<n-1 ; j++){
            tempa = num[i];
            tempb = num[j];
            long long apb = num[i]+num[j];
            int L=j+1, R=n-1, M; // 어차피 while문 끝나고 L과 R의 경우 모두 볼 것이므로 경계값에 1씩 더 둘 필요 없음
            // L~R의 범위 안에서 num[M]-apb의 값이 음수에서 양수가 될 것이다.
            // LR -+ 인 경우를 찾고, 두 인덱스에 해당하는 경우를 비교해야 함
            while (L+1<R){
                M=(L+R)>>1;
                if (num[M]+apb>0) R=M;
                else L=M;
            }
            if (llabs(num[L]+apb)<llabs(num[R]+apb)) tempc=num[L];
            else tempc=num[R];
            if (llabs(tempa+tempb+tempc)<min) {
                a = tempa;
                b = tempb;
                c = tempc;
                min = llabs(a+b+c);
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}