#include <iostream>

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    int num[n], g[n], s[n], b[n];
    int place = 1;
    int idx;
    for (int i=0 ; i<n ; i++){
        cin>>num[i]>>g[i]>>s[i]>>b[i];
        if (num[i] == k) idx = i;
    }
    // 인덱스가 i인 나라의 등수를 구해야 한다.
    for (int i=0 ; i<n ; i++){
        if (i == idx) continue;
        cin>>num[i]>>g[i]>>s[i]>>b[i];
        if (g[i]>g[idx]) place++;
        else if (g[i]==g[idx] && s[i]>s[idx]) place++;
        else if (g[i]==g[idx] && s[i]==s[idx] && b[i]>b[idx]) place++;
    }
    cout<<place;
}