#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool binary_search(int num){
    int L=0;
    int R=v.size()-1;
    int M;
    bool found = false;
    while (L<=R){
        M = (L+R)>>1;
        if (v[M]>num) R=M-1;
        else if (v[M]<num) L=M+1;
        else { // 찾았을 때
            found = true;
            break;
        }
    }
    // found 못하고 나온 경우는 못찾은 경우
    return found;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin>>m;
    for (int i=0 ; i<m ; i++){
        cin>>temp;
        cout<<((binary_search(temp))?"1":"0")<<"\n";
    }
}