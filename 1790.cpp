#include <iostream>

using namespace std;

// 1~9: 1*9 = 9
// 10~99: 2*90 = 180
// 100~999: 3:900 = 2700

int n_len(int n){
    int ret = 0;
    while (n>0){
        n /= 10;
        ret++;
    }
    return ret;
}

int pow_ten(int i){
    int ret = 1;
    while (i--){
        ret *= 10;
    }
    return ret;
}

int main(void){
    int n, k;
    cin>>n>>k;
    int len = 0;
    for (int i=1 ; i<n_len(n) ; i++){
        len += i*9*pow_ten(i-1);
    }
    // 100..0 ~ n까지 마저 더해야 함
    len += (n-pow_ten(n_len(n)-1)+1)*n_len(n);
    if (len < k) {
        cout<<"-1";
        return 0;
    }
    int remain = k;
    int i = 1;
    while (1){
        if (remain <= i*9*pow_ten(i-1)) break;
        remain -= i*9*pow_ten(i-1);
        i++;
    }
    // i: i자리수로 이루어진 범위에서 답을 찾을 수 있음을 의미
    // remain: i자리수 범위 내에서 몇번째인지
    // (remain-1)/i: 10..0 으로부터 몇번째 수인지
    // i-1-(remain-1)%i: 해당 수를 몇번 10으로 나누고 1의 자리를 취해야 하는지
    int target;
    target = pow_ten(i-1) + (remain-1)/i;
    int div = i-1-(remain-1)%i;
    while (div--) target /= 10;
    cout<<(target%10);
    return 0;    
}