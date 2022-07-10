#include <iostream>

using namespace std;

void form(string& num){
    char unit_digit = num[num.size()-1];
    num.pop_back();
    if (num[num.size()-1] < unit_digit){
        for (int i=num.size()-1 ; i>=1 ; i--){
            num[i] += 10;
            num[i-1]--;
            if (num[i-1]>='0') break;
        }
    }
    num[num.size()-1] -= unit_digit-'0';
    while (num[0]=='0') num.erase(0, 1);
}

// long long으로 풀면 쉬우니 string을 이용한 풀이
int main(void){
    int t; cin>>t;
    string num, original_num;
    for (int i=0 ; i<t ; i++){
        if (i!=0) cout<<"\n";
        cin>>num;
        original_num = num;
        while (1){
            // 크기가 2 이하가 되어서 결론이 나야 하는 경우
            if (num.size()<=2) {
                if (num[0]=='0') cout<<num[num.size()-1]<<"\n";
                else cout<<num<<"\n";
                break;
            }
            cout<<num<<"\n";
            form(num);
        }
        cout<<"The number "<<original_num<<" is ";
        if (num[0]!=num[1]) cout<<"not ";
        cout<<"divisible by 11.\n";
    }
    return 0;
}