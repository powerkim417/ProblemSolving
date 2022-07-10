#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> rope;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        rope.push_back(temp);
    }
    sort(rope.begin(), rope.end());
    reverse(rope.begin(), rope.end());
    // 로프를 (i+1)개 골랐을 경우 중 최대는 가장 튼튼한 순서로 (i+1)개를 고르는 경우.
    // 이러한 경우의 총 i=0~n-1 까지의 경우의 최대값들을 비교함. O(n)
    int answer = -1;
    for (int i=0 ; i<n ; i++){
        int temp = rope[i] * (i+1);
        if (temp > answer) answer = temp;
    }
    cout<<answer;
    return 0;
}