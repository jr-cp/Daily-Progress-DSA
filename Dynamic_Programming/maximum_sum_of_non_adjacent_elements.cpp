#include<bits/stdc++.h>
using namespace std;

int msonae_dp(int currInd,int N,vector<int>& memo,vector<int>& nums){
    if(currInd == N)
        return 0;
    if(currInd == N - 1)
        return nums[currInd];
    if(memo[currInd]!=-1)
        return memo[currInd];

    
    int include = nums[currInd] + msonae_dp(currInd + 2, N, memo, nums);
    int exclude = msonae_dp(currInd + 1, N, memo, nums);

    return memo[currInd] = max(include, exclude);
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

        vector<int> memo(N, -1);

        int res = msonae_dp(0, N, memo, nums);
        cout << res << endl;
    }
    return 0;
}