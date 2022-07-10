#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    set<string> M;
    vector<string> answer;
    string temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        M.insert(temp);
    }
    for (int i=0 ; i<m ; i++){
        cin>>temp;
        if (M.find(temp) != M.end()) answer.push_back(temp);
    }
    int num = answer.size();
    sort(answer.begin(), answer.end());
    cout<<num<<"\n";
    for (int i=0 ; i<num ; i++){
        cout<<answer[i]<<"\n";
    }
}