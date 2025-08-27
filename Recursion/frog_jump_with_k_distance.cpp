#include<bits/stdc++.h>
using namespace std;


int frog_jump_II_recursion(int currInd,int N,int k,vector<int>& nums){
    if(currInd == N - 1)
        return 0;

    int res = INT_MAX;
    for (int j = currInd + 1; j <= currInd + k; j++){
        if(j < N){
            int curr = abs(nums[currInd] - nums[j]) + frog_jump_II_recursion(j, N, k, nums);
            res = min(res, curr);

        }
    }

    return res;
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

        int res = frog_jump_II_recursion(0, N, k, energy);
        cout << res << endl;
    }
    return 0;
}