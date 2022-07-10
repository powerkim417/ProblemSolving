#include <iostream>

using namespace std;

int main(void){
    int n;
    string s;
    cin>>n>>s;
    // S와 LL의 갯수 합 + 1
    int cnt = 0;
    bool flag = false;
    for (int i=0 ; i<n ; i++){
        if (s[i]=='S') {
            cnt++;
            flag = false;
        }
        else { // s[i] == 'L'
            if (flag) cnt++; // 연속 L
            flag = !flag; // 연속 L 이었다면 체크 해제, 처음 나온거라면 체크
        }
    }
    cnt++;
    if (n<cnt) cnt = n; // 최대 사람의 수를 넘을 순 없음
    cout<<cnt;
    return 0;
}