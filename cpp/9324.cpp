#include <iostream>

using namespace std;

int cnt[26];

int main(void){
    int t;
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        for (int i=0 ; i<26 ; i++) cnt[i] = 0;
        int len = s.length();
        bool flag = true;
        for (int i=0 ; i<len ; i++){
            cnt[s[i]-'A']++;
            if (cnt[s[i]-'A'] == 3){ // 3번째 등장일 때
                if (s[i+1] != s[i]) {
                    flag = false;
                    break;
                }
                else {
                    cnt[s[i]-'A'] = 0;
                    i++; // 추가 삽입 문자는 카운트하지 않음
                }
            }
        }
        if (flag) cout<<"OK\n";
        else cout<<"FAKE\n";
    }
    return 0;
}