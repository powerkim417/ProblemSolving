#include <iostream>
#include <stack>

using namespace std;

stack<int> s[6];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, p;
    cin>>n>>p;
    int line, fret;
    int cnt = 0;
    for (int i=0 ; i<n ; i++){
        cin>>line>>fret;
        line--;
        if (s[line].empty() || s[line].top() < fret){
            s[line].push(fret);
            cnt++;
        }
        else if (s[line].top() > fret){
            while (!s[line].empty() && s[line].top() > fret){
                s[line].pop();
                cnt++;
            }
            if (s[line].empty() || s[line].top() < fret){
                s[line].push(fret);
                cnt++;
            }
        }
        // top() == fret인 경우는 연속으로 나오는 경우 말곤 없는데, 이 경우는 cnt 추가 없음
    }
    cout<<cnt;
    return 0;
}