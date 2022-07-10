#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int S[n][n];
    vector<int> people;
    vector<int> select;
    for (int i=0 ; i<n ; i++){
        people.push_back(i);
        for (int j=0 ; j<n ; j++){
            cin>>S[i][j];
        }
    }
    for (int i=0 ; i<n/2 ; i++) select.push_back(0);
    for (int i=0 ; i<n/2 ; i++) select.push_back(1);

    int min = 10*100 - 10*1;

    do {
        int team_zero = 0;
        int team_one = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (i==j) continue;
                if (select[i] == select[j]){
                    if (select[i] == 0) team_zero += S[i][j];
                    else team_one += S[i][j];
                }
            }
        }
        int diff = team_zero - team_one;
        if (diff<0) diff = -diff;
        if (diff<min) min = diff;
    } while (next_permutation(select.begin(), select.end()));
    cout<<min;
}