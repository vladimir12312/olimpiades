#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> box;
    freopen("input18.txt","r",stdin);
    freopen("output17.txt","w",stdout);
    int N;
    int temp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        box.push_back(temp);

    }
        vector<int> sum(N);
        vector<int> revsum(N+1);
   // cout<<"pass the 0";
    //calculate the sum
    sum[0]=box[0];
    for(int i=1;i<N;i++){
            //cout<<"stuck0"<<endl;
        sum[i]=sum[i-1]+box[i];

    }
    revsum[N-1]=box[N-1];
    revsum[N]=0;
    for(int i=N-2;i>-1;i--){
            //cout<<"stuck1"<<endl;
        revsum[i]=revsum[i+1]+box[i];

    }
   // cout<<"pass the 1st";
    int totalval=sum[N-1];
    int mindif=totalval;
    int z=1;
    int leftindex=0;//i+1
    int rightindex=0;//z
    //cout<<sum[N-1]<<sum[1]<<revsum[N-1];
    for(int i=-1;i<N-1;i++){
            //cout<<"stuck2";
            if (i==-1){

        z=0;
        while(2*revsum[N-z]<sum[N-1]&&z!=N){
            z++;
        }
if(2*revsum[N-z]-sum[N-1]<sum[N-1]-2*revsum[N-z+1]){
            if(mindif>2*revsum[N-z]-sum[N-1]){
                    mindif=2*revsum[N-z]-sum[N-1];
                    leftindex=i+1;
                    rightindex=z;

            }
        }
        else{
            if(mindif>sum[N-1]-2*revsum[N-z+1]){
                    mindif=sum[N-1]-2*revsum[N-z+1];
                    leftindex=i+1;
                    rightindex=z;

            }
        }

        }
        else if(2*sum[i]<sum[N-1]){
            z=0;
        while(2*sum[i]+2*revsum[N-z]<sum[N-1]&&z!=N){
            z++;
        }
        if(2*sum[i]+2*revsum[N-z]-sum[N-1]<sum[N-1]-2*sum[i]-2*revsum[N-z+1]){
            if(mindif>2*sum[i]+2*revsum[N-z]-sum[N-1]){
                    mindif=2*sum[i]+2*revsum[N-z]-sum[N-1];
                    leftindex=i+1;
                    rightindex=z;


            }
        }
        else{
            if(mindif>sum[N-1]-2*sum[i]-2*revsum[N-z+1]){
                    mindif=sum[N-1]-2*sum[i]-2*revsum[N-z+1];
                    leftindex=i+1;
                    rightindex=z;
                    //cout<<mindif<<endl;


            }
        }
        }
    }
    //cout<<endl;
    cout<<leftindex<<" "<<rightindex;
    //cout<<mindif;

}
