#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, m;
    cin>>n>>m;
    vector<int> safe;
    for (int i=0 ; i<n ; i++){
        int p, l;
        cin>>p>>l;
        vector<int> mile;
        int temp;
        for (int j=0 ; j<p ; j++){
            cin>>temp;
            mile.push_back(temp);
        }
        sort(mile.begin(), mile.end());
        reverse(mile.begin(), mile.end());
        // 마일리지 내림차순으로 정렬
        // 미달인 경우 1만 넣고,
        // 5명중 4명이 들을 수 있다면 4등의 마일리지와 같게 넣으면 수강 가능
        if (p<l) safe.push_back(1);
        else safe.push_back(mile[l-1]);
    }
    // 이제 safe와 m이 쓰임.
    // 안전빵 마일리지를 오름차순 정렬하고, 넘지않는 최대한 듣는다.
    sort(safe.begin(), safe.end());
    // for (int i=0 ; i<n ; i++){
    //     cout<<safe[i]<<endl;
    // }
    int cnt = 0;
    for (int i=0 ; i<n ; i++){
        if (m<safe[i]) break;
        m -= safe[i];
        cnt++;
    }
    cout<<cnt;
}