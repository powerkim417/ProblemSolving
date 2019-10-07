#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct time {
    int s;
    int e;

    inline bool operator<(time a){ // a는 비교대상
        if (e == a.e){
            // 1-3, 2-3 간은 상관없는데 3-3같은 경우는 나중으로 가야 한다.
            // 즉 start 기준 오름차순으로 가자
            return (s<a.s);
        }
        else return (e<a.e);
    }
};

int main(void){
    int n;
    cin>>n;
    time t;
    vector<time> v;
    for (int i=0 ; i<n ; i++){
        cin>>t.s>>t.e;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    // for (int i=0 ; i<n ; i++){
    //     cout<<v[i].s<<" "<<v[i].e<<endl;
    // }

    // 끝나는 시간이 빠른 경우부터 먼저 배정하면 됨!
    // 끝나는 시간이 같은 경우 시작시간이 더 느린 경우부터 먼저 배정
    /* 증명(귀류법)
    가장 빨리 끝나는 회의를 고르는게 이득이 아니라고 가정하면
    ex) [   ]    [ ] [] [  ]
    1) 가정한 최적해의 첫번째 회의가 가장 빠른 회의가 아닌 경우
           [ ][ ][ ] [] [  ] 의 경우 두번째 회의도 진작에 골랐어야 하므로 모순
    2)  [ ][    ][ ] [] [  ] 의 경우 ex의 첫번째 회의보다 2)의 첫번째 회의가 먼저 골라졌어야 하므로 모순
    증명이 좀 찝찝하다...
    */
    int cnt = 1;
    int cur_e = v[0].e;
    for (int i=1 ; i<n ; i++){
        if (v[i].s >= cur_e) {
            cnt++;
            cur_e = v[i].e;
        }
    }
    cout<<cnt;
}