#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int TASKA1002() {
    //5*10^4
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int complects;
    cin>>complects;
    int n;
    int temp;
    vector<int> numbersa;
    vector<int> numbersb;
    int currentnum;
    bool finished;
    bool newelement=true;
    int difnuma;
    int difnumb;
    for(int j=0;j<complects;j++){
        cin>>n;
        difnuma=1;
        difnumb=1;
        finished=false;
        newelement=true;
        //element is 1st of its kind
        numbersa.clear();
        numbersb.clear();
        for(int i=0;i<n;i++){
            cin>>temp;
            numbersa.push_back(temp);
        }
        for(int i=0;i<n;i++){
            cin>>temp;
            numbersb.push_back(temp);
        }

        sort(numbersa.begin(),numbersa.end());
        sort(numbersb.begin(),numbersb.end());
        int currentnum=numbersa[0];
        for(int i=1;i<numbersa.size();i++){
            if(currentnum!=numbersa[i]){
                difnuma++;
                currentnum=numbersa[i];
            }
        }
        currentnum=numbersb[0];
        for(int i=1;i<numbersb.size();i++){
            if(currentnum!=numbersb[i]){
                difnumb++;
                currentnum=numbersb[i];
            }
        }
        if(difnuma>2 || difnumb>2){
            cout<<"YES"<<"\n";
        }
        else if(difnumb==2&&difnuma==2){
                cout<<"YES"<<"\n";
        }
        else{
                cout<<"NO"<<"\n";
        }
    }
     return 0;
}
