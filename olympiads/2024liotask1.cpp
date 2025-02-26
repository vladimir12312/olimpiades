#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//+-O(n)
int lio2024task1(){
    int n,d,m;

    cin>>n>>d>>m;
    int temp;
    vector<int> automati;
    for(int i=0;i<n;i++){
        cin>>temp;
        automati.push_back(temp);


    }
    vector<int> lifesneeded(n+1);
    lifesneeded[n]=-d+1;
    for(int i=n-1;i>=0;i--){
        if(lifesneeded[i]=lifesneeded[i+1]-automati[i]>-d){
            lifesneeded[i]=lifesneeded[i+1]-automati[i]>-d;
        }
        else{
            lifesneeded[i]=-d+1;
        }



    }
    vector<int> choices;
    int currentlifes=0;
    bool finished=false;
    for(int i=0;i<n;i++){
        if(currentlifes+automati[i]>-d){
            if(automati[i]>0){
                choices.push_back(automati[i]);

            }
            else{currentlifes+=automati[i];//cout<<"minus"<<endl;
            }
        }
        else{
            sort(choices.begin(),choices.end());
            while(currentlifes+automati[i]<=-d&&m>0&&choices.size()>0){
                currentlifes+=choices[choices.size()-1];
                choices.erase(choices.end()-1);
                m--;


            }
           // cout<<currentlifes+automati[i]<<endl;
            if(currentlifes+automati[i]<=-d){
                finished=true;
                break;
            }
            if(automati[i]>0){
                choices.push_back(automati[i]);

            }
            else{currentlifes+=automati[i];}
}


    }
    if(finished==true){cout<<"-1 -1";}
    else{
    cout<<m<<" "<<currentlifes+d;
    }
}
