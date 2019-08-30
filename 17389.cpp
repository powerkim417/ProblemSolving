#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int sum=0;
    int bonus=0;
    char c;
    for (int i=1 ; i<=n ; i++){
        cin>>c;
        if (c=='O') {
            sum += bonus++;
            sum += i;
        }
        else {
            bonus = 0;
        }
    }
    cout<<sum;
}