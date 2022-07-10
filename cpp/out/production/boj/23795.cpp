#include <iostream>

using namespace std;

int main(void){
    int n;
    int answer = 0;
    while (cin>>n){
        if (n==-1) break;
        answer += n;
    }
    cout<<answer;
    return 0;
}