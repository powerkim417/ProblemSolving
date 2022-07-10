#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int m,n;
int x,y;
int xdiff, ydiff;
typedef pair<int, int> P;
set<P> star, pic;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>m;
    for (int i=0 ; i<m ; i++){
        cin>>x>>y;
        star.insert({x,y});
    }
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y;
        pic.insert({x,y});
    }
    // 주어진 입력에는 무조건 별자리가 존재하므로, star[0]에 해당하는 별 pic[i]가 무조건 존재한다.
    P star0 = *(star.begin());
    for (auto i: pic){
        xdiff = i.first - star0.first;
        ydiff = i.second - star0.second;
        bool flag = true;
        // 나머지 star[j]들도 pic에 있는지 확인
        for (auto j: star){
            if (pic.find({j.first+xdiff, j.second+ydiff}) == pic.end()){
                flag = false;
                break;
            }
        }
        if (flag) {
            cout<<xdiff<<" "<<ydiff;
            return 0;
        }
    }
}