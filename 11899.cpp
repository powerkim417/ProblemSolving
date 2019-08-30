#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void){
    string str;
    stack<char> s;
    cin>>str;
    int len = str.length();
    s.push(str[0]);
    for (int i=1 ; i<len ; i++){
        if (str[i] == ')' && s.size() != 0 && s.top() == '('){
            // s should not be empty when top called
            s.pop();
        }
        else {
            s.push(str[i]);
        }
    }
    cout<<s.size();
}