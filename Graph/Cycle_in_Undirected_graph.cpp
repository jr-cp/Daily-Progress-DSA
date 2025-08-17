#include<bits/stdc++.h>
using namespace std;

bool dfs(int V,int node,int par,unordered_set<int>& vis,vector<vector<int>>& adj_lst){
    vis.insert(node);

    for(auto nd : adj_lst[node]){
        if(!vis.count(nd)){
            if(dfs(V, nd, node, vis, adj_lst))
            return true;
        } else if(nd != par){
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int V,E;
        cin >> V >> E;
        vector<vector<int>> edges(E);

        for (int i = 0; i < E;i++){
            int f, s;
            cin >> f >> s;

            edges[i] = {f, s};
        }

        vector<vector<int>> adj_lst(V);
        unordered_set<int> vis;

        for (int i = 0; i < E;i++){
            adj_lst[edges[i][0]].push_back(edges[i][1]);
            adj_lst[edges[i][1]].push_back(edges[i][0]);
        }

        bool res = false;

        for (int i = 0; i < V;i++){
            if(!vis.count(i)){
                if(dfs(V,i,-1,vis,adj_lst)){
                    res = true;
                    break;
                }
            }
        }
            cout << (res ? "Cycle exists" : "No cycle exists") << endl;
    }
    return 0;
}