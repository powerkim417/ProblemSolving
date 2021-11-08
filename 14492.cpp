#include <iostream>

using namespace std;

bool a[300][300], b[300][300];

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++) for (int j=0 ; j<n ; j++) cin>>a[i][j];
    for (int i=0 ; i<n ; i++) for (int j=0 ; j<n ; j++) cin>>b[i][j];
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            bool c = false;
            for (int k=0 ; k<n ; k++){
                c |= a[i][k] & b[k][j];
            }
            if (c) answer++;
        }
    }
    cout<<answer;
    return 0;
}