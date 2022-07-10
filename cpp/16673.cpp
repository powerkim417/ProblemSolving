#include <iostream>

using namespace std;

int main(void){
    int c,k,p;
    cin>>c>>k>>p;
    int answer = k*c*(c+1)/2 + p*c*(c+1)*(2*c+1)/6;
    cout<<answer;
}