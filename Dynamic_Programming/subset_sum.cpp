#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int i, int N, int sum, vector<int>& nums, vector<vector<int>>& memo) {
    if (sum == 0) return true;
    if (i == N || sum < 0) return false;
    if (memo[i][sum] != -1) return memo[i][sum];

    if (nums[i] <= sum) {
        if (subset_sum(i + 1, N, sum - nums[i], nums, memo))
            return memo[i][sum] = true;
    }

    return memo[i][sum] = subset_sum(i + 1, N, sum, nums, memo);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> nums(N);
        for (int i = 0; i < N; i++) cin >> nums[i];

        int sum;
        cin >> sum;

        vector<vector<int>> memo(N, vector<int>(sum + 1, -1));
        bool res = subset_sum(0, N, sum, nums, memo);

        if (res) cout << "TRUE";
        else cout << "FALSE\n";
    }
    return 0;
}
