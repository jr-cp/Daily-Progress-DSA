#include<bits/stdc++.h>
using namespace std;


int frog_jump_dp(int currInd,int N,vector<int>& memo,vector<int>& nums){
    if(currInd == N - 1)
        return 0;
    if(memo[currInd] != -1)
        return memo[currInd];

    int one_jump = abs(nums[currInd] - nums[currInd + 1]) + frog_jump_dp(currInd + 1, N, memo, nums);
    int two_jump = INT_MAX;

    if(currInd + 2 < N)
        two_jump = abs(nums[currInd] - nums[currInd + 2]) + frog_jump_dp(currInd + 2, N, memo, nums);

    return memo[currInd] = min(one_jump, two_jump);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> energy(N);

        for (int i = 0; i < N;i++){
            cin >> energy[i];
        }

        vector<int> memo(N, -1);

        int res = frog_jump_dp(0, N, memo, energy);
        cout << res << endl;
    }
    return 0;
}