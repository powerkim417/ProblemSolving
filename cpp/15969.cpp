#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int max = -1, min = 1001, temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        if (max<temp) max = temp;
        if (min>temp) min = temp;
    }
    cout<<max-min;
}