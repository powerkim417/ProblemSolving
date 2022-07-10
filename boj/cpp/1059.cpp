#include <iostream>
#include <set>

using namespace std;

int main(void){
    int len; cin>>len;
    set<int> s;
    int temp;
    for (int i=0 ; i<len ; i++){
        cin>>temp;
        s.insert(temp);
    }
    int n; cin>>n;
    int l, r;
    l = 0;
    for (int i: s){
        if (i>n) {
            if (l==n){ // n이 집합 내의 원소일 경우 좋은 구간이 나올 수 없음
                cout<<"0";
                return 0;
            }
            r = i;
            break;
        }
        l = i;
    }
    l++; r--;
    // cout<<l<<" "<<r<<"\n";
    int answer = 0;
    answer += (n-l)*(r-n); // l r
    answer += (n-l); // l n
    answer += (r-n); // n r
    cout<<answer;
    return 0;
}