#include <iostream>

using namespace std;

int arr[1000];
// i번째 수를 포함하는 왼쪽/오른쪽 가장 긴 증가하는 부분수열 길이
int left_lis[1000];
int right_lis[1000];

// 11053 가장 긴 증가하는 부분 수열의 응용
int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    for (int i=0 ; i<n ; i++){
        int temp = 0;
        for (int j=0 ; j<i ; j++){
            if (arr[j] >= arr[i]) continue;
            if (left_lis[j] > temp) temp = left_lis[j];
        }
        left_lis[i] = temp+1;
    }
    for (int i=n-1 ; i>=0 ; i--){
        int temp = 0;
        for (int j=n-1 ; j>i ; j--){
            if (arr[i] <= arr[j]) continue;
            if (right_lis[j] > temp) temp = right_lis[j];
        }
        right_lis[i] = temp+1;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        // cout<<left_lis[i]<<" "<<right_lis[i]<<"\n";
        if (answer < left_lis[i] + right_lis[i] - 1) answer = left_lis[i] + right_lis[i] - 1;
    }
    cout<<answer;
    return 0;
}