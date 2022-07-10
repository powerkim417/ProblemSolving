#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int cnt[8001]; // idx-4000 이 원하는 값
    int temp;
    double avg = 0;
    vector<int> v;
    set<int> mode; // 최빈값
    set<int>::iterator it;
    for (int i=0 ; i<8001 ; i++) cnt[i] = 0;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        avg += temp;
        v.push_back(temp);
        cnt[temp+4000]++;
    }
    avg /= n;
    sort(v.begin(), v.end());
    int range = v[n-1] - v[0];
    cout<<round(avg)<<"\n"<<v[n/2]<<"\n";
    int m = 0;
    for (int i=0 ; i<n ; i++){
        if (m < cnt[v[i]+4000]){
            m = cnt[v[i]+4000];
            mode.clear();
            mode.insert(v[i]);
        }
        else if (m == cnt[v[i]+4000]){
            mode.insert(v[i]);
        }
    }
    int cbg;
    it = mode.begin();
    if (mode.size() == 1) cbg = *it;
    else cbg = *(++it);
    cout<<cbg<<"\n"<<range;
}