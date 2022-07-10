#include <iostream>

using namespace std;

int main(void){
    int l, s, fine;
    cin>>l>>s;
    if (s<=l) cout<<"Congratulations, you are within the speed limit!";
    else {
        if (s-l<=20) fine = 100;
        else if (s-l<=30) fine = 270;
        else fine = 500;
        cout<<"You are speeding and your fine is $"<<fine<<".";
    }
    return 0;
}