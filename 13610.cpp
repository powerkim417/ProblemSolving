#include <iostream>

using namespace std;

int main(void){
    int x, y;
    cin>>x>>y;
    int answer = y / (y-x);
    if (y % (y-x) != 0) answer++;
    cout<<answer;
    return 0;
}