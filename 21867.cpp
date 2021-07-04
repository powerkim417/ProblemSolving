#include <iostream>

using namespace std;

int main(void){
    int n;
    string s;
    cin>>n>>s;
    bool flag = false;
    for (int i=0 ; i<n ; i++){
        if (s[i] != 'J' && s[i] != 'A' && s[i] != 'V'){
            cout<<s[i];
            flag = true;
        }
    }
    if (!flag) cout<<"nojava";
    return 0;
}