#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1번 실행으로 전부 박탈
// N명의 국회의원의 명예가 각각 1,2,...,N으로 존재해야 하는게 마지노선이며,
// 오름차순으로 했을 때 각각의 숫자의 차이가 1 이하여야 함.
// 차이가 2 이상이라면, 차이가 1이 되도록 명예를 깎고 그만큼 answer에 더함.
// 1 1 1 1 5는 답이 3가 나와야 함


int main(void){
    int n;
    cin>>n;
    long long temp;
    vector<long long> v;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    long long answer = 0;
    // i=0일 때
    if (v[0]>1) {
        answer += v[0]-1;
        v[0] = 1;
    }
    // i>=1일 때
    for (int i=1 ; i<n ; i++){
        if (v[i]-v[i-1]<=1) continue;
        else {
            answer += v[i]-(v[i-1]+1);
            v[i] = v[i-1]+1;
        }
    }
    cout<<answer;
    return 0;
}