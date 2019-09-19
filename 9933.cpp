#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string rev(string s){
    int len = s.length();
    string ret = "";
    for (int i=0 ; i<len ; i++){
        ret = s[i] + ret;
    }
    return ret;
}

int main(void){
    int N;
    cin>>N;
    string s;
    vector<string> v;
    for (int i=0 ; i<N ; i++){
        cin>>s;
        v.push_back(s);
    }
    int sz = v.size();
    string answer;
    for (int i=0 ; i<sz ; i++){
        if (find(v.begin(), v.end(), rev(v[i])) != v.end()){
            answer = v[i];
            break;
        }
    }
    int len = answer.length();
    cout<<len<<" "<<answer[len/2];
}