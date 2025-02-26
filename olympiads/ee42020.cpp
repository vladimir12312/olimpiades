#include <vector>
#include <iostream>
#include <string>
using namespace std;
int Task4ee2020(){
    int N,K;
    cin>>N>>K;
    vector<vector<int>> adjlist(N);
    if(N%K!=0){
        cout<<"fail";
    }
    else{
        //read adjlist
        int peacesize=N/K;
        for(int i=0;i<N;i++){
            //граф двудольный
            cin<<temp1<<temp2;
            adjlist[temp1].push_back(temp2);
            adjlist[temp2].push_back(temp1);

        }

    }

}
