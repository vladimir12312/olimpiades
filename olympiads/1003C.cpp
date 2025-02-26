#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int Task1003C(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int complects;
    cin>>complects;
    vector<int> a;
    vector<int> b;
    bool finished;
    int temp;
    int m,n;
    int INF=-1000000000;
    int lastnum;
for (int j=0;j<complects;j++){

    cin>>n>>m;

    a.clear();
    b.clear();
    finished=false;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        b.push_back(temp);
    }
    sort(b.begin(),b.end());

    lastnum=INF;
    int optimalnext=INF;

    bool isupdated=false;
    int high,low;
    //cout<<endl<<endl;
    for(int i=0;i<n;i++){
            isupdated=false;
            optimalnext=-INF;
            bool finishedsearch=false;
            //need to find lowest index so that b[j]>=lastnum+a[i]
            int optimalmove=-INF;
            bool binfound=false;
            int lookingfor=lastnum+a[i];
             int low=0;
            int high=m-1;
    while(low<=high){

        int mid=(high+low)/2;
        if(b[mid]>=lookingfor){
            if(optimalmove>b[mid]){
                    optimalmove=b[mid];
                    high=mid-1;
                    binfound=true;
            }
        }
        else{
                low=mid+1;
        }
    }
    if(optimalmove-a[i]>=lastnum&&binfound==true){
        if(a[i]<optimalmove-a[i]&&a[i]>=lastnum){
            optimalnext=a[i];
            isupdated=true;
        }
        else{
            optimalnext=optimalmove-a[i];
            isupdated=true;
        }

    }
    else if(a[i]>=lastnum){
            optimalnext=a[i];
            isupdated=true;
    }
    lastnum=optimalnext;
    //cout<<i<<" "<<lastnum<<endl;
   // cout<<i<<" "<<optimalnext<<endl;
    if(isupdated==false){
        finished=true;
        break;

    }
    }
    if(finished==true){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }



    }
}
