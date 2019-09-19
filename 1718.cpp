#include <iostream>

using namespace std;

int main(void){
    string line;
    getline(cin, line);
    string key;
    getline(cin, key);
    int l_len = line.length();
    int k_len = key.length();
    for (int i=0 ; i<line.length() ; i++){
        if (line[i]>='a' && line[i]<='z'){
            line[i] = line[i] - (key[i%k_len]-'a'+1);
            if (line[i]<'a') line[i] += 26;
        }
        cout<<line[i];
    }
}