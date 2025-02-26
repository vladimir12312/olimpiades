/*
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

string names [3] = {"ryytlid", "maagid", "vibulaskjad"};

ll sumn (ll m) {
  return m * (m + 1) / 2;
}

int main () {
  ll n;
  cin >> n;

  // otsime suurimat m nii, et 1 + 2 + ... + m <= n
  ll m = 0;
  for (ll k = 1 << 30; k != 0; k /= 2) {
    if (sumn(m + k) <= n) {
      m += k;
    }
  }
  cout<<m;
  cout << names[m % 3] << '\n';
}

#include <vector>
#include <iostream>
using namespace std;
int main(){
vector<int> numbers={0,2};
int target=1;
 int high=numbers.size()-1;
    int low=0;
    int mid=0;
    //search for lowest, higher than currentx
    int lowestpossible=10000000;
    int lowestpossibleind=-1;
while(low<high+1){

                //cout<<"stuck"<<",high"<<high<<"mid"<<mid<<"low"<<low<<endl;
            mid=(high+low)/2;
            cout<<mid<<endl;
            if(numbers[mid]>target){
                high=mid-1;
                if(lowestpossible>numbers[mid]){
                        lowestpossible=numbers[mid];
                        lowestpossibleind=mid;
                }
            }
            else{
                low=mid+1;

            }
        }
        cout<<lowestpossibleind;
}
*/
