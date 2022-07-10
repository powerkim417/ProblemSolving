#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    double val;
    string unit;
    while (t--){
        cin>>val>>unit;
        cout<<fixed;
        cout.precision(4);
        if (unit == "kg"){
            cout<<val*2.2046<<" lb\n";
        }
        else if (unit == "lb"){
            cout<<val*0.4536<<" kg\n";
        }
        else if (unit == "l"){
            cout<<val*0.2642<<" g\n";
        }
        else if (unit == "g"){
            cout<<val*3.7854<<" l\n";
        }
    }
    return 0;
}