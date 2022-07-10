#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    double a,b,c;
    cin>>a>>b>>c;
    double temp_fat = (double)c;
    double temp_cost = a;
    vector<double> topp;
    double input;
    for (int i=0 ; i<n ; i++) {
        cin>>input;
        topp.push_back(input);
    }
    sort(topp.begin(), topp.end());
    reverse(topp.begin(), topp.end());
    for (int i=0 ; i<n ; i++){
        if (temp_fat/temp_cost < (temp_fat + topp[i])/(temp_cost + b)){
            temp_fat += topp[i];
            temp_cost += b;
        }
    }
    cout<<(int)(temp_fat/temp_cost);
}