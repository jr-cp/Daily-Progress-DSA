#include<bits/stdc++.h>
using namespace std;

int climbing_stairs(int N,vector<int>&memo){
    if(N <= 1)
        return 1;
    else if(memo[N] != -1)
        return memo[N];

    memo[N] = climbing_stairs(N - 1,memo) + climbing_stairs(N - 2,memo);
    return memo[N];
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> memo(N + 1,-1);

        int res = climbing_stairs(N, memo);
        cout << res << endl;
    }
    return 0;
}