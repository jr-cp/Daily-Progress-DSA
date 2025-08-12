#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> gas(N);
    vector<int> cost(N);

    for (int i = 0; i < N;i++){
        cin >> gas[i];
    }

    for (int j = 0; j < N;j++){
        cin >> cost[j];
    }

    int ind = 0;
    for (int k = 0; k < N;k++){
        if(gas[k] < cost[k]){
            ind = ind + 1;
        }
    }

    int res =(ind < N - 1)? ind : -1;
    cout << res;
    return 0;
}