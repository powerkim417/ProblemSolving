#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    string str;
    cin>>str;
    vector<string> v;
    int len = str.length();
    for (int i=0 ; i<len ; i++){
        v.push_back(str);
        str.erase(str.begin());
    }
    sort(v.begin(), v.end());
    for (int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<endl;
    }
}