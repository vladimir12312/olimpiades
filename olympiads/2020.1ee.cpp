#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int Taskee20201(){
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    char temp;
    bool finished=false;
    string fail="EI SAA";
    bitset<1001> dishes;
    bitset<1001> guests;
    bitset<1001> a;
    for(int i=0;i<N;i++){
            cin>>temp;
          //  cout<<temp;
        if(temp=='M'){
        dishes[i]=1;

        }
    }
    for(int i=0;i<N;i++){
        cin>>temp;
        if(temp=='S'){
            guests[i]=1;
        }
    }
    if(guests.count()>(N-dishes.count())){
        cout<<fail<<endl;
    }
    else{
     for(int i=0;i<N+1;i++){
         a=dishes & guests;
        if(a==0 ){
               cout<<i+1;//+1 because its not shifts but index
                finished=true;
               // cout<<guests<<endl;
                //cout<<dishes;
        break;
        }
        else{
            //cout<<guests<<endl;
            //make a shift
            guests[N]=guests[0];
            guests=guests >> 1;
        }

     }
     if (finished==false){
         cout<<fail<<endl;
     }


    }
}
