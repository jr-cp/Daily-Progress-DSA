#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;
int zero_one_knapsack_dp(int i,int N,int w,vector<int>& profit,vector<int>& weights){
    if(i == N || w == 0)
        return 0;
    pair<int, int> st = {i, w};
    if(memo.count(st))
        return memo[st];
    if (weights[i] > w)
    {
        return memo[st] = zero_one_knapsack_dp(i + 1, N, w, profit, weights);
    }

        int include = profit[i] + zero_one_knapsack_dp(i + 1, N, w - weights[i], profit, weights);
        int exclude = zero_one_knapsack_dp(i + 1, N, w, profit, weights);

        return memo[st] = max(include, exclude);
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

        int res = zero_one_knapsack_dp(0, N, w, profit, weights);
        cout << res << endl;
    }
    return 0;
}