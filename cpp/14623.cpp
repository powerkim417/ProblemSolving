#include <iostream>

using namespace std;

int main(void){
    string b1,b2;
    cin>>b1>>b2;
    int l1 = b1.length();
    int l2 = b2.length();
    int a[30], s[60]; // 11..1(30개) = 2^30-1 이 최대이므로 곱셈은 60자리가 최대인 것이 보장
    for (int i=0 ; i<l1 ; i++){
        a[i] = (b1[l1-1-i]-'0');
    }
    for (int i=l1 ; i<30 ; i++){
        a[i] = 0;
    }
    for (int i=0 ; i<60 ; i++){
        s[i] = 0;
    }
    for (int i=l2-1 ; i>=0 ; i--){ // 곰셈수의 각 자리(2^0 부터)
        if (b2[i] == '0') continue;
        // left shift 해야 하는 정도: l2-1-i
        for (int j=0 ; j<30 ; j++){
            s[j+l2-1-i] += a[j];
            if (s[j+l2-1-i] >= 2){
                s[j+l2-1-i+1]++;
                s[j+l2-1-i] -= 2;
            }
        }
        
        // bool flag = false;
        // for (int i=59 ; i>=0 ; i--){
        //     if (s[i] == 1) flag = true;
        //     if (flag || s[i]==1) cout<<s[i];
        // }
        // cout<<endl;
    }
    bool flag = false;
    for (int i=59 ; i>=0 ; i--){
        if (s[i] == 1) flag = true;
        if (flag || s[i]==1) cout<<s[i];
    }
}