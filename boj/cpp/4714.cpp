#include <iostream>

using namespace std;

int main(void){
    double x;
    while (cin>>x){
        if (x==-1) break;
        cout<<fixed;
        cout.precision(2);
        cout<<"Objects weighing "<<x;
        cout<<" on Earth will weigh "<<0.167*x;
        cout<<" on the moon.\n";
    }
    return 0;
}