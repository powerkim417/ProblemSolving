#include <iostream>

using namespace std;

int main(void){
    int n, k;
    cin>>n>>k;
    int cnt = 0;
    for (int h=0 ; h<=n ; h++){
        if (h%10 == k || h/10 == k){ // 해당 3600초동안은 모두 포함 확정
            cnt += 3600;
            continue;
        }
        for (int m=0 ; m<=59 ; m++){
            if (m%10 == k || m/10 == k){ // 해당 60초동안은 모두 포함 확정
                cnt += 60;
                continue;
            }
            for (int s=0 ; s<=59 ; s++){
                if (s%10 == k || s/10 == k) cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}