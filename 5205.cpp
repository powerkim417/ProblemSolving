#include <iostream>
#include <vector>

using namespace std;

int rgb[200][3];
typedef pair<int, int> P;

int dist(int i, int j){ // 비교이므로 그냥 제곱인 상태로 반환
    int ret = 0;
    for (int k=0 ; k<3 ; k++){
        ret += (rgb[i][k]-rgb[j][k])*(rgb[i][k]-rgb[j][k]);
    }
    return ret;
}

int main(void){
    int k, n;
    cin>>k;
    for (int t=1 ; t<=k ; t++){
        cout<<"Data Set "<<t<<":\n";
        cin>>n;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<3 ; j++){
                cin>>rgb[i][j];
            }
        }
        int maxval = -1;
        vector<P> maxv;
        for (int i=0 ; i<n ; i++){
            for (int j=i+1 ; j<n ; j++){
                if (dist(i, j) >= maxval) {
                    if (dist(i, j) > maxval) maxv.clear();
                    maxval = dist(i, j);
                    maxv.push_back({i, j});
                }
            }
        }
        for (P p: maxv){
            cout<<p.first+1<<" "<<p.second+1<<"\n";
        }
    }
    return 0;
}