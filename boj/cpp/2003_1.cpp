#include <iostream>

using namespace std;

// 투 포인터를 이용한 풀이
// M보다 크면 start++, M보다 작으면 end++;
// M인 경우는 둘 중 한 경우에 같이 넣고 처리해도 됨

int main(void){
    int n, m;
    cin>>n>>m;
    int arr[10000];
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    // 투 포인터
    int start=0, end=0;
    int sum=arr[0];
    int cnt=0;
    while (1){
        // cout<<start<<" "<<end<<": "<<sum<<"\n";
        if (sum>=m) {
            if (sum==m) {
                cnt++;
                // cout<<"CATCH!\n";
            }
            sum -= arr[start++];
        }
        else if (sum<m) {
            sum += arr[++end];
        }
        // 루프 탈출 조건
        /*
        end가 n-1(끝)에 도달했을 때 n이 되려면
        현재 부분합이 m보다 작다는 뜻인데,
        더이상 더할 원소가 없으므로 어차피 m에 다시 도달할 수 없음.
        따라서, end=n-1일 때 sum<m이어서 end=n이 되었다면 탈출.
        */
        if (end==n) break;
    }
    cout<<cnt;
    return 0;
}