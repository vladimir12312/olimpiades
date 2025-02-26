#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <deque>
#include <cstdio>
struct edge{
    int x,y,weight;
};
struct coords{
int x,y;
};
using namespace std;
//can use dfs-like algo?
pair<int,int> a;
vector<vector<pair<int,int>>> adjlist;
vector<int> contactnum={0,1,2,3,4};
vector<int> possibleedges={0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0};//1-4,3;2-2,3;3-1,2;4-1,4
vector<vector<int>> possibleweights={{1,1,0,0},{1,0,0,1},{0,0,1,1},{0,1,1,0}};
int Task12015(){
    int INF=10000000;
    int N,M;
    char temp;
    int tempint;
    int int1,int2,int3;
    deque<coords> q;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    /*
    XX..X
    XX.X.
    X.X
    */
    cin>>M>>N;
    //cout<<possibleedges.size();
    edge temppair1,temppair2;
    int z;
    int x,y;
    vector<vector<vector<edge>>> a(N+1,vector<vector<edge>>(M+1));
    vector<vector<int>> dist(N+1,vector<int> (M, INF));
    vector<vector<coords>> from(N+1,vector<coords>(M));
    //transform to adj matrix;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>temp;
            tempint=temp-'0';
            z=tempint-1;
            if(z!=-1){
                for(int x=0;x<possibleedges.size();x+=4){
                    int1=j+possibleedges[x+2];
                    int2=i+possibleedges[x+3];
                    temppair1={(j+possibleedges[x]),(i+possibleedges[x+1]),possibleweights[z][x/4]};
                    temppair2={int1,int2,possibleweights[z][x/4]};
                    //cout<<"tryto alloc"<<int1<<int2;
                    a[int1][int2].push_back(temppair1);
                    //cout<<"suc"<<endl;
                    a[j+possibleedges[x]][i+possibleedges[x+1]].push_back(temppair2);

                }
            }
        }
            }
    /*
    for (auto i : a){
            for(auto l:i){
                    for(auto o:l){
            cout <<o.x<<o.y<<o.weight << endl;}

            }
    }*/
    int startx=0;
    int starty=M;
    dist[startx][starty]=0;
    q.push_back({startx,starty});
    while(!q.empty()){
            coords coord=q.front();
            q.pop_front();
            auto currentlist=a[coord.x][coord.y];

        for(int i=0;i<currentlist.size();i++){
            if(dist[currentlist[i].x][currentlist[i].y]==INF){//to redo for 0-1
                dist[currentlist[i].x][currentlist[i].y]=dist[coord.x][coord.y]+currentlist[i].weight;
                if(currentlist[i].weight==1){
                q.push_back({currentlist[i].x,currentlist[i].y});}

                else{q.push_front({currentlist[i].x,currentlist[i].y});}
                from[currentlist[i].x][currentlist[i].y]=coord;
            }


        }


    }
    cout<<dist[N][0]<<endl;
    coords current={N,0};
    while(current.x!=0 && current.y!=M){
        cout<<from[current.x][current.y].x<<" "<<from[current.x][current.y].y<<endl;
        current={from[current.x][current.y].x,from[current.x][current.y].y};
    }

    return 0;

    //implement 0-1bfs/dijkstra here
}


