#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    string word;
    int len = 0;
    while (cin >> word){
        if (word.compare("<br>")==0){
            cout<<"\n";
            len = 0;
        }
        else if (word.compare("<hr>")==0){
            if (len > 0){
                cout<<"\n";
                len = 0;
            }
            for (int i=0 ; i<80 ; i++) cout<<"-";
            cout<<"\n";
            len = 0;
        }
        else {
            if (len + word.length() > 80){
                cout<<"\n";
                cout<<word;
                len = word.length();
                
            }
            else {
                cout<<word;
                len += word.length();
            }
            if (len < 80){ // 새 개행 내용이 80자 미만인 경우 빈칸 추가
                cout<<" ";
                len++;
            }
        }
    }
}