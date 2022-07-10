#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin>>n>>s;
    if (n<=25) cout<<s;
    else {
        string mid = s.substr(11, n-22); // s[11] ~ s[n-12] 까지
        // cout<<mid<<"\n";
        // if (mid.find(".")==string::npos || mid.back()=='.'){ // 같은 문장
        /*
        계속 틀린 원인은 여기에 있다!!
        <mid 전체에 "."이 없거나, mid의 마지막에만 '.'이 있거나> 가 조건인데
        위의 조건식은 mid = "a.c." 와 같이 마지막에 '.'이 있기만 한 여러 문장인 경우도 포함 시킨다.
        따라서 조건을 mid.substr(0, mid.size()-1)에 "."이 없는 경우로 바꿔야 함
        */
        if (mid.substr(0, mid.size()-1).find(".")==string::npos){ // 같은 문장
            cout<<s.substr(0,11)<<"..."<<s.substr(n-11);
        }
        else { // 다른 문장
            cout<<s.substr(0,9)<<"......"<<s.substr(n-10);
        }
    }
    return 0;
}