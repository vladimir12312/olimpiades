#include<iostream>
#include <cstdio>
using namespace std;
int task1test(){
freopen("input.txt","w",stdout);
for(int j=0;j<316;j++){
for(int i=0;i<316;i++){
    cout<<(i%4)+1;

}
cout<<"\n";
}
}
int maij(){
    freopen("input.txt","w",stdout);
    cout<<200000;
    for(int i=1;i<200001;i++){
        cout<<i<<" ";

    }

}
int maxin(){
    freopen("input.txt","w",stdout);
    cout<<2000<<endl;
    int totalsum=0;
    for(int i=0;i<100000;i++){
        cout<<i<<" "<<i/100<<" "<<i+1<<endl;
        totalsum+=i/100;
    }
    cout<<100000<<" "<<" "<<1<<" "<<1<<endl;
    cout<<totalsum;


}
#include <iostream>
int maiz(){
    freopen("input.txt","w",stdout);
    cout<<100000<<endl;
    for(int i=0;i<100000;i++){
        if(i<50000){
        cout<<1;
        }
        else{cout<<0;}
}
}

