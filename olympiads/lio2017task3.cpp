#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct virve{
    int fromx,tonum,tox,laiks;

};
bool compareropes(virve a, virve b){

    return a.fromx<b.fromx;

}

int task20173(){
    int n,m,v,l;
    vector<int> timesans;
    cin>>n>>m>>v>>l;
    vector<vector<virve>> virves(n);
    for(int i=0;i<v;i++){
        int fromnumt,fromxt,tonumt,toxt,laikst;
        cin>>fromnumt>>fromxt>>tonumt>>toxt>>laikst;
        virve newvirve={fromxt,tonumt-1,toxt,laikst};
        virve newvirve2={toxt,fromnumt-1,fromxt,laikst};
        cout<<"push"<<fromnumt-1<<","<<fromxt<<","<<tonumt-1<<","<<toxt<<","<<laikst<<endl;
        virves[fromnumt-1].push_back(newvirve);
        virves[tonumt-1].push_back(newvirve2);

    }
    vector<int> toanswer;
    for(int i=0;i<l;i++){
    int temp;
    cin>>temp;
    toanswer.push_back(temp);
    }
    for(int i=0;i<n;i++){
        sort(virves[i].begin(),virves[i].end(),compareropes);
    }
    //go through each monkey
    for(int i=0;i<n;i++){
    cout<<"Imfree"<<endl<<endl;
    int currentrope=i;
    int currentx=0;
    int timespend=0;
    while(currentx!=m){
            cout<<"currentx"<<currentx<<"currentrope"<<currentrope<<endl;
            //cout<<"stuckelsewhere";
        //find next rope
        //binsearch?
        int high=virves[currentrope].size();
        int low=0;
        int mid;
        //search for lowest, higher than currentx
        int lowestpossible=10000000;
        int lowestpossibleind=-1;
        for(auto y:virves[currentrope]){cout<<y.fromx<<",";}
        cout<<endl;
        int timeoutcounter=0;
        while(low!=high){

                //cout<<"stuck"<<",high"<<high<<"mid"<<mid<<"low"<<low<<endl;
            mid=(high+low)/2;
            if(virves[currentrope][mid].fromx>currentx){
                high=mid;
                if(lowestpossible>virves[currentrope][mid].fromx){
                        lowestpossible=virves[currentrope][mid].fromx;
                        lowestpossibleind=mid;
                }
            }
            else{
                low=mid+1;

            }
        }
        cout<<"found rope at"<<lowestpossibleind<<","<<currentrope<<","<<lowestpossible<<endl;
        if(lowestpossibleind!=-1){
        timespend=timespend+virves[currentrope][lowestpossibleind].fromx-currentx;
        cout<<"plus"<<virves[currentrope][lowestpossibleind].fromx-currentx<<endl;
        timespend+=virves[currentrope][lowestpossibleind].laiks;
        cout<<"plus"<<virves[currentrope][lowestpossibleind].laiks;
         currentx=virves[currentrope][lowestpossibleind].tox;
        currentrope=virves[currentrope][lowestpossibleind].tonum;

        }
        else{

            timespend+=m-currentx;
            cout<<"plus"<<currentx;
            currentx=m;
        }
    }
    timesans.push_back(timespend);


    }
    sort(timesans.begin(),timesans.end());
    for(auto i:timesans){
        cout<<i<<" ";
    }
    cout<<endl;
    int pointer=0;
    bool finished=false;
    cout<<toanswer[0]<<","<<toanswer[1];
    cout<<endl;
    for(int i=0;i<l;i++){
        while(toanswer[i]>=timesans[pointer]){
            if (pointer!=timesans.size()-1){
            pointer++;
            }
            else if(finished){break;}
            else{pointer++;finished=true;break;}
        }
        cout<<pointer<<" ";
    }

}
