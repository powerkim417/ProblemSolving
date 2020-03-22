#include <iostream>

using namespace std;

int FJ[100001];

// HPS: 각각 012에 대응
int addWin(int fj, int cow){ // 소가 이기면 1, 비기거나 지면 0
    // 01, 12, 20 일 때 이김
    if ((cow-fj+3)%3==1) return 1;
    else return 0;
}

// HHHPPP, HHHSSS, HHHHHH
// PPPPPP, PPPSSS, PPPHHH
// SSSPPP, SSSSSS, SSSHHH 총 9가지 형태

int dp[100001][3][3] = {}; // i번째까지 갔을 때 처음 j모양이고 지금은 k모양

int max(int a, int b){
    return (a>b)?a:b;
}

// DP를 이용한 풀이

int main(void){
    int n;
    char temp;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        switch (temp){
            case 'H':
            FJ[i] = 0;
            break;
            case 'P':
            FJ[i] = 1;
            break;
            case 'S':
            FJ[i] = 2;
            break;
        }
    }
    for (int j=0 ; j<3 ; j++){
        for (int k=0 ; k<3 ; k++){
            if (j!=k) continue; // 처음에 시작과 끝이 다를 수는 없으므로 경우의 수 0인 채로 넘김
            dp[1][j][j] = addWin(FJ[1], j);
        }
    }
    for (int i=2 ; i<=n ; i++){
        // j==k일 때는 i-1의 값에서 addWin 결과만 더해주면 되고
        // j!=k일 때는 (i-1까지 j였다가 i번째에 k로 바뀐 경우)와 (i-1때 이미 j에서 k로 바뀌고, k가 이어지는 경우)의 최댓값으로 한다.
        // 이렇게 j와 k가 다른 경우는 j==k일 때와 이미 j에서 k로 바뀐 경우를 통해서만 합산되므로 두번 이상 바뀔 염려는 하지 않아도 됨
        for (int j=0 ; j<3 ; j++){
            for (int k=0 ; k<3 ; k++){
                if (j==k) {
                    dp[i][j][j] = dp[i-1][j][j] + addWin(FJ[i], j);
                }
                else {
                    dp[i][j][k] = max(dp[i-1][j][j], dp[i-1][j][k]) + addWin(FJ[i], k);
                }
            }
        }
    }
    int answer = 0;
    for (int j=0 ; j<3 ; j++){
        for (int k=0 ; k<3 ; k++){
            if (answer < dp[n][j][k]){
                answer = dp[n][j][k];
            }
        }
    }
    // for (int j=0 ; j<3 ; j++){ // H P S
    //     for (int k=0 ; k<3 ; k++){
    //         cout<<dp[1][j][k]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<answer;
    return 0;
}