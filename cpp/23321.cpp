#include <iostream>
#include <vector>

using namespace std;

int main(void){
    string temp;
    cin>>temp>>temp; // 2번째줄만 읽으면 다 구분가능
    vector<string> answer;
    for (char c: temp){
        if (c=='o') answer.push_back("owln.");
        else if (c=='w') answer.push_back(".omln");
        else answer.push_back("..oLn");
    }
    for (int j=0 ; j<5 ; j++){
        for (int i=0 ; i<answer.size() ; i++){
            cout<<answer[i][j];
        }
        cout<<"\n";
    }
    return 0;
}