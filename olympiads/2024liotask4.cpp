#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int dfs(int currentnode,vector<int> &adjlist,vector<int>& visited,vector<int>&dargumi,vector<int> &dzivot,int initialnode,int& pelna){
    visited[currentnode]=1;
    if(dzivot[initialnode]>0&&dargumi[currentnode]>0){
        if(dzivot[initialnode]<dargumi[currentnode]){
            dargumi[currentnode]-=dzivot[initialnode];
            pelna+=dzivot[initialnode];
            dzivot[initialnode]=0;
        }
        else{
            pelna+=dargumi[currentnode];
            dzivot[currentnode]-=dargumi[currentnode];
            dargumi[currentnode]=0;


        }

    }
    int i=adjlist[currentnode];
        if(visited[i]!=1&&dzivot[initialnode]!=0){
            dfs(i,adjlist,visited,dargumi,dzivot,initialnode,pelna);

        }

    return 0;
}
//greedy aproach?, since you can achieve any further cities if youve achieved the current one
int lio2024task4(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> dargumi;
    vector<int> visited(n);
    vector<int> dzivot;
    int totaldziv;
    int totalsum=0;
    vector<int> adjlist(n);
    for(int i=0;i<n;i++){
        int dziv,amount,to;
        cin>>dziv>>amount>>to;
        dargumi.push_back(amount);
        totalsum+=amount;
        dzivot.push_back(dziv);
        totaldziv+=dziv;
        adjlist[i]=to-1;


    }
    vector<int> possibledargumi(n);
    int pelna=0;
    for(int i=0;i<n;i++){
        visited.assign(n,0);
        dfs(i,adjlist,visited,dargumi,dzivot,i,pelna);

    }
    cout<<pelna<<endl;
    for(auto i:dargumi){
        cout<<i<<" ";
    }
    //cout<<endl<<totalsum;

}
//70 punkti
