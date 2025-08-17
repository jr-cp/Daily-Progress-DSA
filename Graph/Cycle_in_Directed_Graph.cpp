// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

// Output: true
// Explanation: The diagram clearly shows a cycle 0 → 2 → 0
// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]

// Output: false
// Explanation: no cycle in the graph

#include<bits/stdc++.h>
using namespace std;

bool dfs(int V,int node, vector<vector<int>>& adj_lst,vector<int>& vis,vector<int>& path){
    vis[node] = 1;
    path[node] = 1;

    for(auto nd : adj_lst[node]){
        if(!vis[nd] && dfs(V,nd,adj_lst,vis,path))
                return true;
        else if(path[nd] == 1)
            return true;
    }
    path[node] = 0;
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> edges(E);

        for (int i = 0; i < E;i++){
            int f, s;
            cin >> f >> s;

            edges[i] = {f, s};
        }

        vector<vector<int>> adj_lst(V);

        for (int i = 0; i < E;i++){
            adj_lst[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        bool res = false;
        for (int k = 0; k < V;k++){
            if(!vis[k] && dfs(V,k,adj_lst,vis,path)){
                    res = true;
                    break;
                }
            
        }

        cout << (res ? "Cycle exisits in the DAG" : "Cycle does not exist in the DAG") << endl;
    }
    return 0;
}