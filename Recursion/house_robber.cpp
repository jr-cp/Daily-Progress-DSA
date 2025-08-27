#include<bits/stdc++.h>
using namespace std;


int max_sum_no_adj(int curr,int N,vector<int>& nums){
    if(curr >= N)
        return 0;
    if(curr == N - 1)
        return nums[N - 1];

    int include = nums[curr] + max_sum_no_adj(curr + 2, N, nums);
    int exclude = max_sum_no_adj(curr + 1, N, nums);

    return max(include, exclude);
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

            int res = max(max_sum_no_adj(0,N - 1,arr1),max_sum_no_adj(0,N - 1,arr2));
            cout << res << endl;
        }
    return 0;
}