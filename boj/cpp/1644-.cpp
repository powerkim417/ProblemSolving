#include <iostream>
#include <vector>
#define MAX 4000000

using namespace std;

bool isPrime[MAX+1] = {};
vector<int> prime;

// 투 포인터
// 에라토스테네스로 소수를 모두 판별(O(N))한 뒤,
// 소수의 갯수만큼 한번 더 순회(O(소수갯수(N))). 이는 N보다 작으므로 전체는 O(N)

int main(void){
    int N;
    cin>>N;
    // N<=4000000인데, 한가지 소수의 합으로 나타나는 경우도 있으므로 4000000까지의 모든 소수를 확인해야 한다.
    for (int i=2 ; i<=MAX ; i++){
        isPrime[i] = true;
    }
    for (int p=2 ; p*p<=MAX ; p++){ // 소수 후보
        if (!isPrime[p]) continue;
        for (int i=2 ; i*p<=MAX ; i++) {// 소수의 배수들 체크
            isPrime[i*p] = false;
        }
    }
    for (int i=2 ; i<=MAX ; i++){
        if (isPrime[i]) prime.push_back(i);
    }
    int v_size = prime.size();
    int l=0, r=0; // [l, r). 처음에는 아무것도 포함하지 않은 상태
    int sum=0;
    int cnt=0;
    while (r<v_size){
        if (sum<N){
            sum += prime[r++];
        }
        else if (sum>N){
            sum -= prime[l++];
        }
        else {
            cnt++;
            // 아래 둘 중 하나 다 가능
            // sum += prime[r++]; 
            sum -= prime[l++];
        }
    }
    cout<<cnt;
    return 0;
}