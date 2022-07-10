#include <iostream>

using namespace std;

int nine_count(int num){
    int cnt = 0;
    for (int i=0 ; i<5 ; i++){
        if (num%10 == 9) cnt++;
        num /= 10;
    }
    return cnt;
}

int main(void){
    int n,m;
    cin>>n>>m;
    int nine_num[n+1][m+1]; // 끝 숫자는 sum
    int temp;
    for (int i=0 ; i<n ; i++)
        nine_num[i][m] = 0;
    for (int j=0 ; j<m ; j++)
        nine_num[n][j] = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>temp;
            nine_num[i][j] = nine_count(temp);
            nine_num[i][m] += nine_num[i][j];
            nine_num[n][j] += nine_num[i][j];
        }
    }
    int total = 0;
    int max = 0;
    for (int i=0 ; i<n ; i++){
        total += nine_num[i][m];
        if (nine_num[i][m] > max){
            max = nine_num[i][m];
        }
    }
    for (int j=0 ; j<m ; j++){
        if (nine_num[n][j] > max){
            max = nine_num[n][j];
        }
    }
    // cout<<"----"<<endl;
    // for (int i=0 ; i<=n ; i++){
    //     for (int j=0 ; j<=m ; j++){
    //         cout<<nine_num[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<total-max<<endl;
}