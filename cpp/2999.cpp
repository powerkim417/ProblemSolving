#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    string s;
    cin >> s;
    int len = s.length();
    int r,c;
    for (int i=1 ; i<=sqrt(len) ; i++){
        if (len%i != 0) continue;
        c = len/i;
        r = i;
    }
    char word[r][c];
    string::iterator it = s.begin();
    for (int i=0 ; i<c ; i++){
        for (int j=0 ; j<r ; j++){
            word[j][i] = *it;
            it++;
        }
    }
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (word[i][j]<'a' || word[i][j]>'z')
                break;
            cout<<word[i][j];
        }
    }
    
    return 0;
}
