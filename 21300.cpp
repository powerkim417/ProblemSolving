#include <iostream>

using namespace std;

int main(void){
    int sum=0, temp;
    for (int i=0 ; i<6 ; i++){
        cin>>temp;
        sum += temp;
    }
    cout<<sum*5;
    return 0;
}