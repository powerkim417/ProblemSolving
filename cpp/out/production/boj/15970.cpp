#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<int> white, black;
    int num, color;
    for (int i=0 ; i<n ; i++){
        cin>>num>>color;
        if (color==1) white.push_back(num);
        else black.push_back(num);
    }
    int sum = 0;
    sort(white.begin(), white.end());
    sort(black.begin(), black.end());
    int w_size = white.size();
    int b_size = black.size();
    for (int i=0 ; i<w_size ; i++){
        if (i==0) sum += white[i+1]-white[i];
        else if (i==w_size-1) sum += white[i]-white[i-1];
        else {
            sum += (white[i+1]-white[i] > white[i]-white[i-1]) ? white[i]-white[i-1] : white[i+1]-white[i];
        }
    }
    for (int i=0 ; i<b_size ; i++){
        if (i==0) sum += black[i+1]-black[i];
        else if (i==b_size-1) sum += black[i]-black[i-1];
        else {
            sum += (black[i+1]-black[i] > black[i]-black[i-1]) ? black[i]-black[i-1] : black[i+1]-black[i];
        }
    }
    cout<<sum;
}