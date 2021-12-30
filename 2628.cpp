#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int r, c;
    cin>>r>>c;
    int n; cin>>n;
    bool isVert; int num;
    vector<int> hor, vert;
    hor.push_back(0);
    vert.push_back(0);
    hor.push_back(c);
    vert.push_back(r);
    for (int i=0 ; i<n ; i++){
        cin>>isVert>>num;
        if (isVert) vert.push_back(num);
        else hor.push_back(num);
    }
    sort(hor.begin(), hor.end());
    sort(vert.begin(), vert.end());
    int max_hor = -1;
    int max_vert = -1;
    for (int i=1 ; i<hor.size() ; i++){
        if (max_hor < hor[i]-hor[i-1]) max_hor = hor[i]-hor[i-1];
    }
    for (int i=1 ; i<vert.size() ; i++){
        if (max_vert < vert[i]-vert[i-1]) max_vert = vert[i]-vert[i-1];
    }
    // cout<<max_hor<<" "<<max_vert<<"\n";
    cout<<max_hor*max_vert;
    return 0;
}