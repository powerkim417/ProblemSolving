#include <iostream>

using namespace std;

int main(void){
    int sum=0, min=101, temp;
    for (int i=0 ; i<3 ; i++){
        cin>>temp;
        sum += temp;
        if (min>temp) min = temp;
    }
    sum -= min;
    cout<<sum;
    return 0;
}