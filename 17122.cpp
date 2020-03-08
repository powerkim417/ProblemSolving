#include <iostream>

using namespace std;

// 검은색: 1,3,5,7,10,12,14,16 (mod 16)+1

bool color(int x){ // 검은색 false, 흰색 true
    int mod = x%16;
    if (mod==0) mod = 16;
    if (mod%2==0){
        if (mod>8) return false;
        else return true;
    }
    else {
        if (mod>8) return true;
        else return false;
    }
}

int main(void){
    int T;
    cin>>T;
    string s;
    int a, b;
    while (T--){
        cin>>s>>b;
        a = (s[0]-'A'+1) + 8*(s[1]-'0'-1);
        // cout<<color(a)<<" "<<color(b)<<"   ";
        if (color(a) == color(b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}