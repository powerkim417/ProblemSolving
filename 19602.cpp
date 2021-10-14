#include <iostream>

using namespace std;

int main(void){
    int s,m,l;
    cin>>s>>m>>l;
    int score = s+2*m+3*l;
    if (score >= 10) cout<<"happy";
    else cout<<"sad";
    return 0;
}