#include <iostream>
#include <stack>

using namespace std;

int main(void){
    string str, bomb;
    cin>>str>>bomb;
    int slen = str.length();
    int blen = bomb.length();
    stack<pair<char, int>> s; // 글자, 콤보
    if (str[0] == bomb[0]) s.push({str[0], 1});
    else s.push({str[0], 0});
    for (int i=1 ; i<slen ; i++){
        // i-1번째 글자까지 k콤보였다면(k=s.top().second)
        // i번째 글자는 bomb[k]와 같은지 확인
        // 같으면 combo[i]=k+1, 다르면 combo[i]=0
        int k = s.top().second;
        if (str[i] == bomb[k]){
            s.push({str[i], k+1});
        }
        else {
            s.push({str[i], 0});
        }
        if (s.top().second == blen){
            for (int j=0 ; j<blen ; j++){
                s.pop();
            }
        }
    }
    string answer = "";
    while (!s.empty()){
        answer = s.top().first + answer;
        s.pop();
    }
    cout<<answer;
    cout<<endl<<cnt;
}