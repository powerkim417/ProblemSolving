#include <iostream>

using namespace std;

// L<=   <=D를 만족하고, 각 자리수의 합이 X인 최소값 N, 최대값 M을 구하는 문제

int digitSum(int x){
    int ret = 0;
    while (x>0){
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main(void){
    int l,d,x;
    cin>>l>>d>>x;
    int n = d, m = l;
    for (int i=l ; i<=d ; i++){
        if (digitSum(i) != x) continue;
        if (n > i) n = i;
        if (m < i) m = i;
    }
    cout<<n<<"\n"<<m;
    return 0;
}