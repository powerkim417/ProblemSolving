#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int a, b, c;
    cin>>a>>b>>c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(a*b);
    v.push_back(b*c);
    v.push_back(c*a);
    v.push_back(a*b*c);
    sort(v.begin(), v.end(), greater<>());
    for (int i=0 ; i<v.size() ; i++){
        if (v[i]%2 == 0) continue;
        cout<<v[i];
        return 0;
    }
    // 전부다 짝수여서 여기까지 온 경우
    cout<<v[0];
    return 0;

}