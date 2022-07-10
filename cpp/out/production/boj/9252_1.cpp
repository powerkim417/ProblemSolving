#include <iostream>

using namespace std;

string lcs[1001][1001] = {};

int max(int a, int b){
    return (a>b)?a:b;
}

// 매 경우의 LCS를 저장하는 방식의 풀이
// 배열값이 0으로 초기화되므로 인덱스를 1~n으로 활용하면 인덱스 0일 때의 예외처리를 해줄 필요가 없어짐
int main(void){
    string a,b;
    cin>>a>>b;
    for (int i=1 ; i<=a.size() ; i++){
        for (int j=1 ; j<=b.size() ; j++){
            if (a[i-1]==b[j-1]) lcs[i][j] = lcs[i-1][j-1] + a[i-1];
            else {
                // 스페셜저지 이므로 등호 처리는 둘다 ok
                if (lcs[i-1][j].size() > lcs[i][j-1].size()) lcs[i][j] = lcs[i-1][j]; 
                else lcs[i][j] = lcs[i][j-1];
            }
        }
    }
    // for (int i=0 ; i<a.size() ; i++){
    //     for (int j=0 ; j<b.size() ; j++){
    //         cout<<lcs[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<lcs[a.size()][b.size()].size()<<"\n";
    if (lcs[a.size()][b.size()].size() != 0) cout<<lcs[a.size()][b.size()];
    return 0;
}