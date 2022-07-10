#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> T;
    int temp=1;
    while (1){
        if (temp*(temp+1)/2>1000) break;
        T.push_back(temp*(temp+1)/2);
        temp++;
    } // 1000 이하 삼각수 저장 
    int n;
    cin>>n;
    int num;
    for (int i=0 ; i<n ; i++){
        cin>>num;
        bool flag = false;
        for (int a: T){
            for (int b: T){
                for (int c: T){
                    if (num == a+b+c){
                        flag = true;
                    }
                }
            }
        }
        cout<<((flag)?"1":"0")<<"\n";
    }
}