#include <iostream>

using namespace std;

int main(void){
    int a,b,n,w;
    cin>>a>>b>>n>>w;
    int cur_s = 1;
    int cur_l = n-1;
    int cnt = 0;
    int ans_s, ans_l;
    while (cur_l > 0){
        if (cur_s*a + cur_l*b == w) {
            cnt++;
            ans_s = cur_s;
            ans_l = cur_l;
        }
        cur_s++;
        cur_l--;
    }
    if (cnt == 1) cout<<ans_s<<" "<<ans_l;
    else cout<<"-1";
}