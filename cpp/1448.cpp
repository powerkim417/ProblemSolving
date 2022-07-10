#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 길이가 큰 변부터 체크
// len[0], len[1], len[2] 부터 비교.. 만약 0 >= 1+2 면 0과 다른 두 변들이 와도 전부 만족 못하니까 0은 부적합
// 1부터 다시 비교..
// i=len.size()-3일 때까지 비교해서 안되면 -1 반환
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> len;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        len.push_back(temp);
    }
    sort(len.begin(), len.end());
    reverse(len.begin(), len.end());
    for (int i=0 ; i<=len.size()-3 ; i++){
        if (len[i] < len[i+1]+len[i+2]) {
            cout<<(len[i]+len[i+1]+len[i+2]);
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}