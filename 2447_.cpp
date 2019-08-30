#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    char map[n][n];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            map[i][j] = '*';
        }
    }
    int k = 0;
    vector<int> kernel_size;
    while (n>1){
        n /= 3;
        kernel_size.push_back(n); // 9, 3, 1
        k++;
    }
    
    

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }

}