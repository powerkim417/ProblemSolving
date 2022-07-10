#include <iostream>

using namespace std;

int main(void){
    int n;
    string s, answer = "";
    cin>>n>>s;
    for (int i=0 ; i<n ; i++){
        if (s[i] != 'J' && s[i] != 'A' && s[i] != 'V'){
            answer += s[i];
        }
    }
    if (answer.size() != 0) cout<<answer;
    else cout<<"nojava";
    return 0;
}