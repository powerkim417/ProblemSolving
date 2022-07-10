#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP: LIS 문제인 것을 눈치채는 것이 중요한 문제
/*
Ex)
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
일 때, 이를 정렬하면
1 8
2 2
3 9
4 1
6 4
7 6
9 7
10 10
이고, 이중 최소 제거로 제시된 전깃줄을 없애면
2 2
6 4
7 6
9 7
10 10
이다. 오른쪽이 오름차순인 형태

즉, 왼쪽을 정렬한 상태에서의 오른쪽 수열에서 LIS를 찾는 문제
*/
int main(void){
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for (int i=0 ; i<n ; i++){
        pair<int, int> temp;
        cin>>temp.first>>temp.second;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    vector<int> dp;
    for (int i=0 ; i<n ; i++){
        int temp = 0;
        for (int j=0 ; j<i ; j++){
            if (v[j].second >= v[i].second) continue;
            if (dp[j] > temp) temp = dp[j];
        }
        dp.push_back(temp+1);
    }
    int answer = 0; // LIS의 길이
    for (int a: dp){
        if (a > answer) answer = a;
    }
    // 답은 전깃줄 갯수에서 LIS 길이를 뺀 값
    cout<<(n-answer);
    return 0;
}