#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
int TASKB1003(){
    int complects;
    cin>>complects;
    string current;
    bool finished;
for (int j=0;j<complects;j++){
    cin>>current;
    char previous=current[0];
    finished=false;
    for(int i=1;i<current.size();i++){
        if(previous==current[i]){
            finished=true;
            break;
        }
        else{
                previous=current[i];
        }


    }
    if(finished==true){
        cout<<1<<"\n";
    }
    else{
            cout<<current.size()<<"\n";
            }



}

}
