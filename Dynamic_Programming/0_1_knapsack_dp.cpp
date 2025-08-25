#include<bits/stdc++.h>
using namespace std;

int zero_one_knapsack_dp(int i,int N,int w,vector<int>& profit,vector<int>& weights,vector<vector<int>>& memo){
    if(i == N || w == 0)
        return 0;
    if(memo[i][w] != -1)
        return memo[i][w];
    if (weights[i] > w)
    {
        return zero_one_knapsack_dp(i + 1, N, w, profit, weights,memo);
    }

        int include = profit[i] + zero_one_knapsack_dp(i + 1, N, w - weights[i], profit, weights,memo);
        int exclude = zero_one_knapsack_dp(i + 1, N, w, profit, weights,memo);

        return memo[i][w] = max(include, exclude);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;


        vector<int> profit(N), weights(N);

        for (int i = 0; i < N;i++){
            cin >> profit[i];
        }

        for (int i = 0; i < N;i++){
            cin >> weights[i];
        }

        int w;
        cin >> w;

        vector<vector<int>> memo(N,vector<int>(w + 1,-1));


        int res = zero_one_knapsack_dp(0, N, w, profit, weights,memo);
        cout << res << endl;
    }
    return 0;
}