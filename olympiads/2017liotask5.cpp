#include <cmath>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int lio2017task5(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n,m;
    cin>>n>>m;
    long long Z;
    long long z;
    long double  maxz=sqrt(n);
    long double sqmaxz=sqrt(maxz);
    long long sqmaxzint=sqmaxz;
    int todeduct=0;
    long long intmaxz=0;
    //i=z`
    //z=z
    for(int i=1;i<=sqmaxzint;i++){
        if(maxz!=static_cast<long long>(maxz)){
            break;
        }
        intmaxz=static_cast<long long>(maxz);
        if(intmaxz%i==0){
            z=intmaxz/i;
        }
        if(m%(intmaxz/z)==0){
            todeduct++;
            continue;
        }


    }
    cout<<intmaxz<<todeduct<<","<<m<<endl;
    cout<<m+n-todeduct-1;
}
