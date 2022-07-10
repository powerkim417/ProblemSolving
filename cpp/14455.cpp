#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int milk[7] = {};
string name[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
vector<pair<int, string>> v;

int main(void){
    int n;
    cin>>n;
    string s;
    int temp;
    while (n--){
        cin>>s>>temp;
        for (int i=0 ; i<7 ; i++){
            if (s.compare(name[i])==0){
                milk[i] += temp;
                break;
            }
        }
    }
    for (int i=0 ; i<7 ; i++){
        v.push_back({milk[i], name[i]});
    }
    sort(v.begin(), v.end());
    // 전부다 least일 때 -> Tie
    if (v[0].first == v[6].first){
        cout<<"Tie";
        return 0;
    }
    // answer를 가진 소가 2마리 이상일 때 -> Tie
    for (int i=1 ; i<7 ; i++){
        if (v[i].first > v[0].first){ // 두번째로 작은 값을 발견
            if (v[i+1].first == v[i].first) { // 그러나 이 값이 동점일 경우   
                cout<<"Tie";
                return 0;
            }
            else {
                cout<<v[i].second;
                return 0;
            }
        }
    }
}