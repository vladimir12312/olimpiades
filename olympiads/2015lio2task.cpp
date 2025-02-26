#include <vector>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int Task20152(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> numbers;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        numbers.push_back(temp);

    }
    int l;
    int r;
    int j;
    vector<int> leftfori;
    vector<int> rightfori(N);
    long long amountofpl;
    long long oddcount=0;
    long long evencount=0;
    bool finished=false;
    stack<int> left;
    stack<int> right;
    //defining our stacks
    int current;
      for(int i=0;i<N;i++){
        while(left.empty()==false && numbers[left.top()]<numbers[i]){
            left.pop();
        }
        if(left.empty()==false){leftfori.push_back(left.top());}
        else{leftfori.push_back(-1);}
        left.push(i);

    }
    for(int i=N-1;i>-1;i--){
        while(right.empty()==false && numbers[right.top()]<numbers[i]){
            right.pop();
        }
        if(right.empty()==false){rightfori[i]=right.top();}
        else{rightfori[i]=N;}
        right.push(i);

    }
    for(int i=0;i<N;i++){
        l=leftfori[i];
        r=rightfori[i];
        //i-current
        //find lowest
        j=i-1;
        finished=false;

        amountofpl=(i-l)*(r-i);
        //cout<<l<<" "<<r<<endl;
        //cout<<"-----"<<amountofpl<<" "<<i<<endl;
        if(numbers[i]%2==0){
            evencount+=amountofpl;
        }
        else{
            oddcount+=amountofpl;
        }

    }
cout<<oddcount<<" "<<evencount;


}
