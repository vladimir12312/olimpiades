#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int TASK999C() {
    long long answ;
    int complects;
    cin>>complects;

    vector<int> numbers;
    int n;
    long long mod=998244353;
    int temp;
    for(int j=0;j<complects;j++){
        cin>>n;

        numbers.push_back(0);

        for(int i=0;i<n;i++){
            cin>>temp;
            numbers.push_back(temp);

        }
        n++;
        vector<long long> dp(n);
        //cout<<"pastin";
        dp[0]=1;
        //cout<<"pastlogic";
        for(int i=1;i<n;i++){
            if(numbers[i-1]==numbers[i]){

                dp[i]=(dp[i-1]+dp[i])%mod;

            }
            if(i>1 && numbers[i]==numbers[i-2]+1){
               // cout<<i<<endl;
                dp[i]=(dp[i-2]+dp[i])%mod;
            }

        }
        if(n>1){
        answ=(dp[n-1]+dp[n-2])%mod;
        }
        cout<<answ<<"\n";
        dp.clear();
        numbers.clear();


    }
     return 0;
}
