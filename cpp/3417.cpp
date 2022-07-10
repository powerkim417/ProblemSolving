#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string key, text;
    while (cin>>key){
        if (key == "0") break;
        cin>>text;
        for (int i=0 ; i<text.size() ; i++){
            char newchar = text[i] + key[i%key.size()]-'A'+ 1;
            if (newchar > 'Z') newchar -= 26;
            cout<<newchar;
        }
        cout<<"\n";
    }
    return 0;
}