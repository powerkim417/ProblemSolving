#include <iostream>
#include <stack>

using namespace std;

// 결국 (), [] 원소들에 몇을 곱한 값들끼리 더해지는지가 관건
// 그래서 (), []가 붙어있는 경우를 따로 계산해야 한다.
// (()[[]])([]) 의 경우
//  2  3    3 이 있고
// 2*2 = 4
// 3*3*2 = 18
// 3*2 = 6
// 즉 4+18+6 = 28 이 나오는 것!

int main(void){
    string str;
    cin>>str;
    stack<char> s;
    int score = 0; // 최대 3^15 = 14,348,907
    int temp = 1;
    for (string::iterator it=str.begin() ; it!=str.end() ; it++){
        if (*it == ']'){
            if (!s.empty() && s.top() == '['){
                if (it!=str.begin() && *(it-1)=='[') score += temp;
                s.pop();
                temp /= 3;
            }
            else {
                cout<<"0";
                return 0;
            }
        }
        else if (*it == ')'){
            if (!s.empty() && s.top() == '('){
                if (it!=str.begin() && *(it-1)=='(') score += temp;
                s.pop();
                temp /= 2; // 현재 단계의 곱수를 유지하기 위해 다시 /2 해주는것
            }
            else {
                cout<<"0";
                return 0;
            }
        }
        else if (*it == '['){
            s.push(*it);
            temp *= 3;
        }
        else { // '('
            s.push(*it);
            temp *= 2;
        }
    }
    if (!s.empty()) cout<<"0";
    else cout<<score;
    return 0;
}