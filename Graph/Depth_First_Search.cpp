#include<bits/stdc++.h>
using namespace std;

void dfs(int N,int node,vector<int>&res,unordered_set<int>&visited,vector<vector<int>>&adj_lst){
    if(visited.count(node))
        return;
    else{
        res.push_back(node);
        visited.insert(node);

        for(int nd: adj_lst[node]){
            dfs(N, nd, res, visited, adj_lst);
        }
    }
    
}
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges{{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<vector<int>> adj_lst(N);

    for (int i = 0; i < N; i++) {
        adj_lst[i] = edges[i];
    }

        vector<int> res;
        unordered_set<int> visited;

        for (int i = 0; i < N;i++){
            if(!visited.count(i)){
                dfs(N, i, res, visited, adj_lst);
            }
        }

        for(auto k : res){
            cout << k << " ";
        }

            return 0;
}