#include <iostream>
#include <stack>

using namespace std;

// 스택
// 스택에는 낮은 연산자 -> 높은 연산자 순으로 쌓여야 한다
// 높은 연산자를 이용한 연산이 먼저 출력되어야 한다는 의미
// (*)에 /가 들어가려는 경우: *를 내보내고 /가 들어간다
// (+)에 /가 들어가려는 경우: /가 들어간다
// (*)에 -가 들어가려는 경우: *를 내보내고 -가 들어간다
// 같은 단계의 연산자끼리 비교할 때는 먼저 들어간 연산자가 더 우선이므로 나중에 들어가는 같은 단계의 연산자는 스택에 들어가지 못함

/* 현재 문자            꺼낼 수 있는 문자
    (                          없음
    *, /                    *, /(같은 우선순위의 먼저 쌓인 연산들)
    +, -                    *, /(더 높은 우선순위의 연산들), +, -
    )                       *, /, +, -, (
*/

int main(void){
    stack<char> s; // 연산자가 담김
    string str;
    cin>>str;
    for (int i=0 ; i<str.size() ; i++){
        if (str[i]>='A' && str[i]<='Z') {
            cout<<str[i]; // 피연산자는 바로 출력
        }
        else if (str[i]=='('){
            s.push(str[i]);
        }
        else if (str[i]==')'){
            while (s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            s.pop(); // '('
        }
        else if (str[i]=='*' || str[i]=='/'){
            while (!s.empty() && (s.top()=='*' || s.top()=='/')){
                cout<<s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i]=='+' || str[i]=='-'){
            while (!s.empty() && (s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')){
                cout<<s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}