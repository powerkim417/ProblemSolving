#include <iostream>
#include <algorithm>

using namespace std;

bool isPalin(string s){
    int len = s.length();
    for (int i=0 ; i<len/2 ; i++){
        if (s[i] != s[len-1-i]) return false;
    }
    return true;
}

// 그냥 dp로 안풀음..

string rev(string temp){
    reverse(temp.begin(), temp.end());
    return temp;
}

string S;

int main(void){
    cin>>S;
    int i=0;
    // 'xy'bccb
    // 'xy'bccb'x' (X)
    // 'xy'bccb'yx' (O) 이런 식으로!
    string ans;
    while (1){
        ans = S + rev(S.substr(0, i++));
        if (isPalin(ans)) break;
    }
    cout<<ans.length();
}