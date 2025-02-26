#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int lio2017task1(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,K;
    cin>>N>>K;
    int G;
    cin>>G;
    vector<int> answers;
    vector<int> currentpoints(N);
    int temp;

    for(int i=0;i<G;i++){
        cin>>temp;
        answers.push_back(temp);

    }
    int pointsgained;
    int currentparticipant=0;
    bool iscorrect=false;
    int sumoverall=0;
    for(int i=0;i<G;i++){
            if(iscorrect==false){iscorrect=true;}
            else{iscorrect=false;}
        if(iscorrect && answers[i]!=0){
            if(answers[i]/N>=K){
                sumoverall=answers[i]/(N*K);
                answers[i]-=N*K*sumoverall;
               // cout<<"sumoverall"<<i<<endl;
            }
            int answersleft=answers[i];

            if(answersleft/K>1){pointsgained=K+1;}
            else{pointsgained=answersleft;}
            currentpoints[currentparticipant]+=pointsgained;
            int shift=((answersleft-1)/K)+1;
            if(currentparticipant+shift-1>N){
                int lastpart=(currentparticipant+shift-1)%N;
                //cout<<endl<<"last"<<lastpart<<endl;
                currentpoints[0]+=pointsgained;
                currentpoints[lastpart]-=pointsgained;
                currentpoints[lastpart]+=answersleft-(K*(shift-1));
                currentpoints[lastpart+1]-=answersleft-(K*(shift-1));


            }
            else{
            if(shift==1){
           // cout<<endl<<"shift1"<<endl;
            //currentpoints[currentparticipant]+=pointsgained;
            if(currentparticipant+1<N){
            currentpoints[(currentparticipant+1)%N]-=pointsgained;
            }

            }
            else{
                currentpoints[(currentparticipant+shift-1)%N]-=pointsgained;

                if(currentparticipant+1<N){
                    currentpoints[currentparticipant+1]+=answersleft-(K*(shift-1));
                    if(currentparticipant+2<N){
                    currentpoints[currentparticipant+2]-=answersleft-(K*(shift-1));
                }
                //else{
                    //currentpoints[0]-=answersleft-(K*(shift-1));

                //}
                }
                else{
                    currentpoints[0]+=answersleft-(K*(shift-1));
                    currentpoints[1]-=answersleft-(K*(shift-1));


                }

            }
            }
            //cout<<shift<<" "<<currentparticipant<<" "<<i<<" "<<pointsgained<<endl;

            currentparticipant=(currentparticipant+shift-1)%N;
            //cout<<"part change"<<shift-1<<endl;
        }
        else if(answers[i]==0){continue;}
        else{

            currentparticipant=(currentparticipant+answers[i])%N;
        }
        //for(int j=0;j<N;j++){cout<<currentpoints[j]<<" ";}
        //cout<<endl<<currentparticipant<<" pointsg"<<pointsgained<<"i"<<i<<endl;

    }
    int currentsum=0;
    //cout<<endl;
    for(int i=0;i<N;i++){
        //cout<<currentpoints[i]<<endl;
        currentsum+=currentpoints[i];
        cout<<currentsum+sumoverall<<" ";
    }
    return 0;

}
