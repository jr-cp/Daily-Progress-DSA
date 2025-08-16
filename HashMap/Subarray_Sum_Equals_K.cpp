// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 
#include<bits/stdc++.h>
using namespace std;


int subarray_sum_equals_k(int N,int K,vector<int>& nums){
    unordered_map<int, int> cMap;
    cMap[0] = 1;

    int sum = 0,cnt = 0;

    for (int i = 0; i < N;i++){
        sum += nums[i];

        if(cMap.count(sum - K))
            cnt+=cMap[sum - K];
        cMap[sum]++;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N,K;
        cin >> N >> K;
        vector<int> nums(N);

        for (int i = 0; i < N;i++){
            cin >> nums[i];
        }

            int num = subarray_sum_equals_k(N, K, nums);
        cout << num << endl;
    }
    return 0;
}