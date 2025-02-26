#include <vector>
#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
int lio2017task4(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char temp;
    int k;
    int n;
    bitset<100000> virkne;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp-'0'==1){
            virkne.set(i);
        }

    }
    //checking for symbols
    vector<int> pairs;
    int lastsymbol=virkne[0];
    bool checking=true;
    for(int i=0;i<n;i++){
        if(checking==false){lastsymbol=virkne[i+1];checking=true;continue;}
        if(lastsymbol!=virkne[i]){
            pairs.push_back(i-1);
            checking=false;
        }
        else{lastsymbol=virkne[i];}


    }
    cout<<pairs.size();
    int pairsadded=0;
    int pointer=0;
    int pairsskipped=0;
    cout<<endl;
    while(k!=pairsadded+pairs.size()){
            //cout<<"itter";
        if(pointer<n){
            if(pointer==pairs[pairsskipped]){
                cout<<virkne[pointer]<<virkne[pointer+1];
                pointer+=2;
                pairsskipped++;

            }
            else{
            lastsymbol=virkne[pointer];
            cout<<virkne[pointer];
            if(lastsymbol==0){cout<<1;}
            else{cout<<0;}
            pointer++;
            pairsadded++;
            }

        }
        else{cout<<"01";
        pairsadded++;}

    }
    if(pointer<n){
        while(pointer!=n){
            cout<<virkne[pointer];
            pointer++;
        }
    }



}
