#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string doc, word;
    getline(cin, doc);
    getline(cin, word);
    int cnt = 0;
    int idx = 0;
    int loc;
    while (1){
        loc = doc.find(word, idx);
        if (loc != string::npos){
            // cout<<loc<<" ";
            cnt++;
            idx = loc + word.size();
        }
        else break;
    }
    cout<<cnt;
    return 0;
}