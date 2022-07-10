#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, l;
    cin>>n>>l;
    int temp;
    vector<int> fruit;
    for (int i=0 ; i<n ; i++){
        cin>>temp;
        fruit.push_back(temp);
    }
    sort(fruit.begin(), fruit.end());
    for (int f: fruit){
        if (l>=f) l++;
        else break;
    }
    cout<<l;
    return 0;
}