#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int TASKC1001() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int complects;
    cin >> complects;
    //cout << complects << endl;
    vector<long long> numbersarr;
    long long n;
    long long  temp;
    long long size1;
    long long sum;
    long long summax;
    for (int j = 0; j < complects; j++) {
        //cout << "newcomplect";
        numbersarr.clear();
        cin >> n;
        //cout << n << endl;
        summax = 0;
        for (int i = 0; i < n; i++) {
            //cout << "in temp";
            cin >> temp;
            numbersarr.push_back(temp);
            //sum=a[n]-a[1]
        }
        //greedy approach

        sum = 0;
        size1 = numbersarr.size();
        for (int i = 0; i < numbersarr.size(); i++) {
            sum = sum + numbersarr[i];

        }
        summax = sum;
        while (size1 != 1) {
           // cout << "while";
            if (numbersarr[size1 - 1] - numbersarr[0] < numbersarr[0] - numbersarr[size1 - 1]) {
              //  cout << "3";
                reverse(numbersarr.begin(), numbersarr.end());

            }
            if (numbersarr[size1 - 1] - numbersarr[0] > summax) {
              //  cout<<"2";
                summax = numbersarr[size1 - 1] - numbersarr[0];
            }
            //do a minus
            for (int i = 0; i < numbersarr.size() - 1; i++) {
               // cout << "1";
                numbersarr[i] = numbersarr[i + 1] - numbersarr[i];

            }
            numbersarr.erase(numbersarr.end()-1);
            size1 = numbersarr.size();

        }
        cout << summax << "\n";


    }

}
