#include <iostream>

using namespace std;

int main(void){
    string S;
    cin>>S;
    int len = S.length();
    int sum = 0, temp = 0;    
    for (int i=0 ; i<len ; i++){
        if (S[i] == ','){
            sum += temp;
            temp = 0;
        }
        else {
            temp *= 10;
            temp += S[i]-'0';
        }
    }
    sum += temp;
    cout<<sum;
}