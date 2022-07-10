#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){ // 뒤가 더 큰 경우가 true
    if (a.length() < b.length()) return true;
    else if (a.length() == b.length()){
        return (a < b);
    }
    else return false;
}

int main(void){
    int n;
    cin>>n;
    vector<string> s;
    string temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        s.push_back(temp);
    }
    sort(s.begin(), s.end(), cmp);
    cout<<s[0]<<"\n";
    for (int i=1 ; i<n ; i++){
        if (s[i].compare(s[i-1]) != 0) cout<<s[i]<<"\n";
    }
    // for (int i=0 ; i<n ; i++){
    //     cout<<s[i]<<"\n";
    // }
}