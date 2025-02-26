#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
int TaskA1003(){
    int complects;
    cin>>complects;
    string current;
for (int j=0;j<complects;j++){

    cin>>current;
    current.erase(current.end()-2,current.end());
    current.append(1,'i');
    cout<<current<<"\n";




}

}
