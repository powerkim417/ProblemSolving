#include <iostream>

using namespace std;

bool contains(int num, int digit){
    while (num>0){
        if (num%10 == digit) return true;
        num /= 10;
    }
    return false;
}

int main(void){
    int n, l;
    cin>>n>>l;
    int cur = 0;
    int cnt = 0;
    while (cnt<n){
        cur++;
        if (contains(cur, l)) continue;
        cnt++;
        // cout<<cnt<<": "<<cur<<"\n";
    }
    cout<<cur;
    return 0;
}