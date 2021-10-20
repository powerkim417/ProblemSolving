#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

bool valid(string s){
    int vowel = 0, nonvowel = 0;
    for (char c: s){
        if (isVowel(c)) vowel++;
        else nonvowel++;
    }
    if (vowel>=1 && nonvowel>=2) return true;
    else return false;
}

void dfs(int cur, string pw, vector<char>& alpha, int l){
    // if (cur>=0) cout<<alpha[cur]<<" "<<pw<<"\n";
    if (pw.size()==l){
        if (valid(pw)) cout<<pw<<"\n";
        return;
    }
    for (int next=cur+1 ; next<alpha.size() ; next++){
        dfs(next, pw+alpha[next], alpha, l);
    }
}

int main(void){
    int l,c;
    cin>>l>>c;
    char temp;
    vector<char> alpha;
    for (int i=0 ; i<c ; i++){
        cin>>temp;
        alpha.push_back(temp);
    }
    sort(alpha.begin(), alpha.end());
    dfs(-1, "", alpha, l);
    return 0;
}