#include <vector>
#include <iostream>
using namespace std;
int gdc(int a, int b){
    if(a==0){
        return b;
    }
    return gdc(a%b,a);
}
int main(){
int k;
cin>>k;
for(int i=0;i<k;i++){
    int n,m;
    cin>>n>>m;
    int g=gdc(n,m);
    int answ1=(m*(n/g)*(1+n/g))/2;
    int answ2=((m/g)-1)*((m*n)/(2*g));
    int answ=answ1+answ2;
    //cout<<answ1<<" "<<answ2<<endl;
    cout<<answ<<endl;

}
}
