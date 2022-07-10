#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, k;
string word;
bool exists[50][21] = {};

string alpha = "bdefghjklmopqrsuvwxyz";
map<char, int> mp;
int answer = -1;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    k -= 5;
    if (k<0){
        cout<<"0";
        return 0;
    }
    vector<int> choose; // 21개 중 k개 선택
    for (int i=0 ; i<21 ; i++){
        if (i<21-k) choose.push_back(0);
        else choose.push_back(1);
    }
    for (int i=0 ; i<21 ; i++) mp.insert({alpha[i], i});

    for (int i=0 ; i<n ; i++){
        cin>>word;
        for (char c: word){
            if (mp.find(c) != mp.end()) exists[i][mp[c]] = true;
        }
    }
    // for (int j=0 ; j<21 ; j++){
    //     cout<<alpha[j]<<" ";
    // }
    // cout<<"\n";
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<21 ; j++){
    //         cout<<exists[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    do {
        int temp = 0;
        for (int i=0 ; i<n ; i++){
            bool flag = true;
            for (int j=0 ; j<21 ; j++){
                if (!choose[j] && exists[i][j]){
                    flag = false;
                    break;
                }
            }
            if (flag) temp++;
        }
        if (answer < temp) answer = temp;
    } while (next_permutation(choose.begin(), choose.end()));
    cout<<answer;
    return 0;
}