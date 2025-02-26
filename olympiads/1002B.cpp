#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int TASK1002B() {
    //5*10^4
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int complects;
    cin>>complects;
    int n,k;
    int temp;
    bool finished;
    vector<int> numbers;
    int curval;
    int arrsize;
    for(int j=0;j<complects;j++){
        cin>>n>>k;
        curval=2;
        finished=false;
        for(int i=0;i<n;i++){
            cin>>temp;
            numbers.push_back(temp);
        }
        //cout<<arrsize<<k<<endl;
        curval=2;
       if(n==k){
           curval=1;

        for(int i=1;i<n;i+=2){
            //cout<<"into the calc"<<i<<endl;
            if(numbers[i]!=curval){
                finished=true;
                break;
            }
            else{curval++;}

        }
       }
       else{
        for(int i=1;i<n-k+2;i++){
            if(numbers[i]!=1){
                curval=1;
                break;
            }
        }
       }
       if(curval>(k/2)+1){curval=(k/2)+1;}
        cout<<curval<<"\n";
        numbers.clear();
    }
     return 0;
}
