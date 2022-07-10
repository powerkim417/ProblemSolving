#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin>>n;
    string str;
    for (int i=0 ; i<n ; i++){
        cin>>str;
        stack<char> s;
        int len = str.length();
        for (int j=0 ; j<len ; j++){
            if (str[j] == '('){
                s.push('(');
            }
            else { // str[j] ==')'
                if (s.size() >= 1 && s.top() == '('){
                    s.pop();
                }
                else s.push(')');
            }
        }
        if (s.size() != 0) cout<<"NO";
        else cout<<"YES";
        cout<<"\n";
    }
}