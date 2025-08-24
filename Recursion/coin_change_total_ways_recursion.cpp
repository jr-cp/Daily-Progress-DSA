#include<bits/stdc++.h>
using namespace std;

// Input: sum = 4, coins[] = [1, 2, 3]
// Output: 4
// Explanation: There are four solutions: [1, 1, 1, 1], [1, 1, 2], [2, 2] and [1, 3]

int coin_change(int i,int N,int sum,vector<int>& coins){
    if(sum == 0){
        return 1;
    }

    int cnt = 0;
    for (int it = i; it < N;it++){
        if(sum - coins[it] >= 0){
            cnt += coin_change(it, N, sum - coins[it],  coins);
        }
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> coins(N);

        for (int i = 0; i < N;i++){
            cin >> coins[i];
        }

        int sum, tot = 0;
        cin >> sum;

        int res = coin_change(0, N, sum,  coins);
        cout << res << endl;
    }
    return 0;
}