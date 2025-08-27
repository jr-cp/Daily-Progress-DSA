#include<bits/stdc++.h>
using namespace std;


int max_sum_no_adj(int curr,int N,vector<int>& nums,vector<int>& memo){
    if(curr >= N)
        return 0;
    if(curr == N - 1)
        return nums[N - 1];
    if(memo[curr] != -1)
        return memo[curr];

    int include = nums[curr] + max_sum_no_adj(curr + 2, N, nums,memo);
    int exclude = max_sum_no_adj(curr + 1, N, nums,memo);

    return memo[curr] = max(include, exclude);
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

        vector<int> arr1,arr2;
        for(int i = 0; i < N;i++){
            if(i!=N - 1) arr1.push_back(nums[i]);
            if(i != 0) arr2.push_back(nums[i]);
        }

        vector<int> memo1(N - 1,-1),memo2(N - 1, -1);

        int res = max(max_sum_no_adj(0,N - 1,arr1,memo1),max_sum_no_adj(0,N - 1,arr2,memo2));
        cout << res << endl;
        }
    return 0;
}