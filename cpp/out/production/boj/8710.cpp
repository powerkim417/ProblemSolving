#include <iostream>

using namespace std;

int main(void){
    int k,w,m;
    cin>>k>>w>>m;
    w -= k;
    int answer = w/m;
    if (w%m != 0) answer++;
    cout<<answer;
    return 0;
}