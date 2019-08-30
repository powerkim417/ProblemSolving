#include <iostream>

using namespace std;

long long int dp[101];

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        if (i<=5) dp[i] = i;
        else dp[i] = 0;
    }
    for (int i=6 ; i<=n ; i++){
        long long int temp = dp[i-1] + 1; // 바로 전 길이에서 +1 하는 경우
        for (int j=3 ; j<=i-1 ; j++){
            if (temp < dp[i-j]*(j-1))
                temp = dp[i-j]*(j-1);
                /*
                ACV: 3개의 명령어로 2배
                ACVV: 4개의 명령어로 3배
                ...
                AC...V: (i-1)개의 명령어로 (i-2)배
                dp[i-j]에서 j개의 명령어를 사용하여
                (j-1)배 해서 i개의 명령어가 될 때
                나오는 값들 중 최대값을 고른다.

                한편
                ACVACVVV(8개): 2*4=8배
                ACVVVVVVV(9개): 8배 이므로
                어느정도 이상의 긴 길이는 비효율적일 수 있으나,
                d[n-9]*8+1, d[n-9]*8 과 같은 꼴로
                앞 값이 더 커서 조건문에서 그냥 배제되므로
                논리 흐름에 오류를 발생하진 않는다. 시간만 먹을뿐..
                */
        }
        dp[i] = temp;
    }
    cout<<dp[n];
}