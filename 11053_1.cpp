#include <iostream>

using namespace std;

int dp[1000] = {};

/* O(n^2)
앞 원소 중 자신(i)보다 작은 원소(j)들을 체크하면서
(dp[j]들 중 가장 큰 값 + 1)을 부여
자신보다 작은 원소가 없다면 dp[i] = 1
10 20 10 30 20 50
 1  2  1  3  2  4

10 20 10 50 30 40
 1  2  1  3  3  4 

10 20 60 70 10 40
 1  2  3  4  1  3
*/

int main(void){
    int n;
    cin>>n;
    int arr[1000];
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    for (int i=0 ; i<n ; i++){
        int temp = 0;
        for (int j=0 ; j<i ; j++){
            if (arr[j] >= arr[i]) continue;
            if (temp < dp[j]) temp = dp[j];
        }
        // 이렇게 하면 j중에 자기보다 작은 원소가 있을 경우도 만족하고
        // 자기보다 작은 원소가 없을 경우 1을 반환하기도 만족한다.
        dp[i] = temp + 1;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        if (answer < dp[i]) answer = dp[i];
    }
    cout<<answer;
    return 0;
}