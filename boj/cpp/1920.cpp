#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> num;
    int temp;
    for (int i=0 ; i<n ; i++) {
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    int m;
    cin>>m;
    int cur;
    bool flag;
    // binary search는 L, R을 관리하는 것이 핵심
    // L 이상 R "미만!"
    int L, R;
    for (int i=0 ; i<m ; i++){
        flag = false;
        L = 0;
        R = n-1;
        cin>>temp;
        while (L<=R){
            cur = (L+R)/2;
            if (temp == num[cur]) {
                flag = true;
                break;
            }
            else if (temp<num[cur]){
                // 0과 cur-1 사이의 평균
                R = cur-1;
            }
            else if (num[cur]<temp){
                // cur+1과 n-1 사이의 평균
                L = cur+1;
            }
        }
        if (flag) cout<<"1\n";
        else cout<<"0\n";
    }
}