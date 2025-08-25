#include<bits/stdc++.h>
using namespace std;

int lis_DP(int prevInd,int currInd,int N,vector<vector<int>>& memo,vector<int>& nums){
    if(currInd == N)
        return 0;
    if(memo[prevInd + 1][currInd] != -1){
        return memo[prevInd + 1][currInd];
    }

    int include = 0;
    if(prevInd == -1 || nums[prevInd] < nums[currInd]){
        include = 1 + lis_DP(currInd, currInd + 1, N, memo, nums);
    }
    int exclude = lis_DP(prevInd, currInd + 1, N, memo, nums);

    return memo[prevInd + 1][currInd] = max(include, exclude);
}


int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> nums(N);

        for (int i = 0; i < N;i++){
            cin >> nums[i];
        }

        vector<vector<int>> memo(N + 1, vector<int>(N,-1));

        int res = lis_DP(-1, 0, N, memo, nums);
        cout << res << endl;
    }
    return 0;
}