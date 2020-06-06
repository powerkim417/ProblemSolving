#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
vector<long long> num;

/* 풀이 2. O(n^2)
단일포문 + 투포인터
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
    // a를 먼저 구하고 (O(n))
    // 나머지 범위에서 b,c를 투 포인터로 조절해가면서 최적을 찾는다. (O(n))
    // 그러면 전체 시간복잡도는 O(n^2)

    long long sum, min = 1000000000LL+999999999LL+999999998LL;
    long a=0, b=0, c=0; // 답으로 출력할 세 용액
    // 세 용액을 각각 i,j,k(i<j<k)라고 하고 탐색
    for (int i=0 ; i<n-2 ; i++){
        int j=i+1, k=n-1; // i 이후의 부분집합의 양 끝에서 시작. 이 방법은 여러 케이스 중 하나만 찾아도 될 때만 통하는듯..
        while (j<k){
            sum = num[i]+num[j]+num[k];
            if (llabs(sum)<min){
                min = llabs(sum);
                a = num[i];
                b = num[j];
                c = num[k];
            }
            else { // sum의 절대값을 줄여야 한다!
                if (sum>0) k--; // 더 작은 값을 더해야 함
                else if (sum<0) j++; // 더 큰 값을 더해야 함
                else { // 정답
                    break;
                }
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}