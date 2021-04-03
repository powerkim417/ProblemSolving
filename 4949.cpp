#include <iostream>
#include <stack>

using namespace std;

int main(void){
    string temp;
    stack<char> s;
    int n;
    bool flag;
    while (getline(cin, temp)){
        if (temp.compare(".")==0) break;
        // cout<<temp<<"\n";
        s = stack<char>();
        n = temp.size();
        flag = true;
        for (int i=0 ; i<n ; i++){
            if (temp[i]=='['){
                s.push(temp[i]);
            }
            else if (temp[i]=='('){
                s.push(temp[i]);
            }
            else if (temp[i]==']'){
                if (s.empty() || s.top()=='(') {
                    flag = false;
                    break;
                }
                else if (s.top()=='[') s.pop();
            }
            else if (temp[i]==')'){
                if (s.empty() || s.top()=='[') {
                    flag = false;
                    break;
                }
                else if (s.top()=='(') s.pop();
            }
        }
        if (!s.empty()) flag = false;
        if (flag) cout<<"yes\n";
        else cout<<"no\n";
    }
}