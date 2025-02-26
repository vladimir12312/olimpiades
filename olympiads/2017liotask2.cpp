#include <vector>
#include <iostream>
#include <bitset>
struct coords{
int x,y;
};
using namespace std;
int task20172(){
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int n,m;
cin>>n>>m;
vector<coords> fragmenti;
vector<coords> dots;
vector<bitset<100000>> available(n);
int tempx;
int tempy;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>tempx>>tempy;
        dots.push_back({tempx-1,tempy-1});

    }
}
vector<int> displacementsx={1,0,-1,0};
vector<int> displacementsy={0,1,0,-1};
int currentfrag;
bool shouldset=true;
int elementspassed=0;
//cout<<"1st";
while(dots.size()!=elementspassed){
        //cout<<"2nd";
        //cout<<"lim"<<dots.size()<<endl;
        //cout<<elementspassed<<endl;
        auto current=dots[elementspassed];
         if(available[current.x][current.y]==1){
            //cout<<"3rd";
            shouldset=true;

         }


    if(shouldset){
        //cout<<"place:"<<current.x<<";"<<current.y<<endl;
        for(int p=0;p<4;p++){
        if(current.x+displacementsx[p]>-1&&current.y+displacementsy[p]>-1){
         available[current.x+displacementsx[p]].set(current.y+displacementsy[p]);
         //cout<<"set:"<<current.x+displacementsx[p]<<";"<<current.y+displacementsy[p];
        }
        }
        elementspassed++;
        }
    else{
        //cout<<"pushback";
        dots.push_back(dots[elementspassed]);
        elementspassed++;
    }

        shouldset=false;
    }
    cout<<elementspassed;
}
