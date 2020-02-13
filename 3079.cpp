#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> time;
long long n,m;

// 28초에 7 10 칸일 경우 cnt = 4 + 2 = 6. 6명이 가능
// 27초에 7 10 칸일 경우 cnt = 3 + 2 = 5. 6명은 불가능
// 사람을 어디 배치시킬지의 문제에서
// 특정 시간 안에 사람의 배치가 가능한지의 문제로 전환!!!!!!!!

bool check(long long t){
    long long cnt = 0;
    for (long long i=0 ; i<n ; i++){
        cnt += t/time[i];
    }
    return (cnt>=m);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    long long temp;
    long long max_t=0;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        if (max_t < temp) max_t = temp;
        time.push_back(temp);
    }
    // m명의 인원이 특정 시간 안에 통과할 수 있는지. 특정 시간을 이분탐색으로!
    long long L = 0;
    long long R = max_t*m;
    long long M;
    // n * log(m*Tk)
    // 10^6 * log(10^18) = 10^6 * log(2^60) = 60*10^6
    while (L+1<R){
        M = (L+R)>>1; // 짝수일 때 왼쪽 선택
        if (check(M)){ // 가능한 경우 왼쪽으로
            R = M;
        }
        else {
            L = M;
        }
    }
    /*
    나올 때
    LR
    XO 와 같이 나옴
    그러면 답은 R
    */
    cout<<R;
}