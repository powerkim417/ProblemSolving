#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<int> time;
    int temp;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        time.push_back(temp);
    }
    sort(time.begin(), time.end());
}