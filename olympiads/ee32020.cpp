///*
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long answ=0;
    long long a;
    for(long long i=1<<30;i>0;i/=2){
            a=(i+answ)*(i+answ+1)/2;
        if(a<=n){
            answ+=i;
        }
    }
   // cout<<answ<<endl;
    cout<<answ%3;

}
//*/
