#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct score {
    int n;
    int sum;
    int three;
    int two;
    int one;
};

score s[4];

// int cmp(const score &a, const score &b){ // a<b: -, a=b: 0, a>b: +
//     if (a.sum<b.sum) return -1;
//     else if (a.sum==b.sum){
//         if (a.three<b.three) return -1;
//         else if (a.three==b.three){
//             if (a.two<b.two) return -1;
//             else if (a.two==b.two) return 0;
//             else return 1;
//         }
//         else return 1;
//     }
//     else return 1;
// }

bool cmpByRule(const score &a, const score &b){ // a<b: -, a=b: 0, a>b: +
    if (a.sum<b.sum) return true;
    else if (a.sum==b.sum){
        if (a.three<b.three) return true;
        else if (a.three==b.three){
            if (a.two<b.two) return true;
            else if (a.two==b.two) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

bool isEqual(const score &a, const score &b){
    if (a.sum==b.sum && a.three==b.three && a.two==b.two && a.one==b.one) return true;
    else return false;
}

int main(void){
    int n;
    cin>>n;
    int temp[4];
    vector<score> v;
    for (int i=1 ; i<=3 ; i++) s[i].sum = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=1 ; j<=3 ; j++){
            cin>>temp[j];
            s[j].sum += temp[j];
            switch (temp[j]){
                case 1:
                s[j].one++;
                break;
                case 2:
                s[j].two++;
                break;
                case 3:
                s[j].three++;
                break;
            }
        }
    }
    for (int i=1 ; i<=3 ; i++) {
        s[i].n = i;
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end(), cmpByRule); // 오름차순
    for (int i=0 ; i<3 ; i++){
        // cout<<"["<<v[i].n<<"]:"<<v[i].sum<<"("<<v[i].three<<" "<<v[i].two<<" "<<v[i].one<<")\n";
    }
    if (isEqual(v[2], v[1])){
        cout<<"0 ";
    }
    else {
        cout<<v[2].n<<" ";
    }
    cout<<v[2].sum;
    return 0;
}