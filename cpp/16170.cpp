#include <iostream>
#include <ctime>

using namespace std;

int main(void){
    time_t my_time = time(NULL);
    struct tm *now = localtime(&my_time);

    cout<<(now->tm_year + 1900)<<"\n";
    cout<<(now->tm_mon + 1)<<"\n";
    cout<<(now->tm_mday);
}