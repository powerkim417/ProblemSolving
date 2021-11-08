#include <iostream>

using namespace std;

int n;
int num[2000];
bool isPalin[2000][2000] = {};
/*
  1 2 1 3 1 2 1
1 O X O X X X O
2   O X X X O X
1     O X O X X
3       O X X X
1         O X O
2           O X
1             O
s~e까지가 팰린드롬 이려면, s+1 ~ e-1까지가 팰린드롬이고 arr[s]==arr[e] 여야 한다
(그래프 기준으로 우상향으로 dp가 뻗어나감)
*/

void init_palin(){
    // dp가 크기 2씩 증가하므로 길이 1,2에 대해서는 초기값 설정을 해줘야 함
    for (int i=0 ; i<n ; i++) isPalin[i][i] = true;
    for (int i=1 ; i<n ; i++) if (num[i]==num[i-1]) isPalin[i-1][i] = true;
    for (int i=n-1 ; i>=0 ; i--){ // [i+1] 에서 [i]로 가는 것이므로, 뒤 인덱스가 먼저 차있어야 한다. 즉 역순으로 돌아야 함
        for (int j=i+2 ; j<n ; j++){
            if (isPalin[i+1][j-1] && num[i]==num[j]) isPalin[i][j] = true;
        }
    }
}

// 시간 0.5촤서 O(NM)으론 안됨
// 숫자 누적형 DP가 아니라 binary DP
int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>num[i];
    }
    init_palin();
    int m;
    cin>>m;
    int s, e;
    for (int i=0 ; i<m ; i++){
        cin>>s>>e;
        s--; e--;
        cout<<isPalin[s][e]<<"\n";
    }
    return 0;
}