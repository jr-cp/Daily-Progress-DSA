#include<bits/stdc++.h>
using namespace std;

int frog_jump_at_k_dis(int currInd,int N,int k,vector<int>& memo,vector<int>& nums){
    if(currInd == N - 1)
        return 0;

    if(memo[currInd] != -1)
        return memo[currInd];

    int one_jump = INT_MAX;

    for (int j = currInd + 1; j <= currInd + k && j < N;j++){
        int cur = abs(nums[currInd] - nums[j]) + frog_jump_at_k_dis(j, N, k, memo, nums);
        one_jump = min(cur, one_jump);
    }

    return memo[currInd] = one_jump;
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

        int k;
        cin >> k;

        vector<int> memo(N, -1);

        int res = frog_jump_at_k_dis(0, N, k, memo, energy);

        cout << res << endl;
    }
    return 0;
}