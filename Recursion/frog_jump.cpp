#include<bits/stdc++.h>
using namespace std;


int frog_jump(int i,int N,vector<int>& nums){
    if(i == N - 1)
        return 0;

    int one_jump = abs(nums[i] - nums[i + 1]) + frog_jump(i + 1, N, nums);
    int two_jump = INT_MAX;

    if(i + 2 < N){
        two_jump = abs(nums[i] - nums[i + 2]) + frog_jump(i + 2, N, nums);
    }

    return min(one_jump, two_jump);
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

        int res = frog_jump(0, N, energy);
        cout << res << endl;
    }
    return 0;
}