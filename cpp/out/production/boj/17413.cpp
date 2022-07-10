#include <iostream>
#include <stack>

using namespace std;

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    stack<char> st;
    bool tag = false;
    for (int i=0 ; i<=s.size() ; i++){
        if (i==s.size() || s[i]==' '){
            if (tag) cout<<s[i];
            else {
                // 단어가 끝나는 바로 다음
                while (!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                if (i!=s.size()) cout<<" ";
            }
        }
        else if (s[i]=='<'){
            // 단어가 끝나는 바로 다음
            while (!st.empty()){
                cout<<st.top();
                st.pop();
            }
            tag = true;
            cout<<s[i];
        }
        else if (s[i]=='>'){
            tag = false;
            cout<<s[i];
        }
        else {
            if (tag) cout<<s[i];
            else st.push(s[i]);
        }
    }
    return 0;
}