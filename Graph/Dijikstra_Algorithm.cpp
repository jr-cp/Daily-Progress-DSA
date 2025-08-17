#include<bits/stdc++.h>
using namespace std;

vector<int> dijikstra(int V,int E,int src,vector<vector<pair<int,int>>>& adj_lst){
    vector<int> dis(V,1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    dis[src] = 0;

    minheap.push({0, src});
    
    while(!minheap.empty()){
        int currD = minheap.top().first, currNode = minheap.top().second;
        minheap.pop();

        for(auto nd : adj_lst[currNode]){
            int dist = currD + nd.second;
            if(dis[nd.first] > dist){
                dis[nd.first] = dist;
                minheap.push({dis[nd.first], nd.first});
            }
        }
    }
    return dis;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int V, E,src;
        cin >> V >> E >> src;

        vector<vector<int>> edges(E);

        for (int i = 0; i < E;i++){
            int n1, n2, dis;
            cin >> n1 >> n2 >> dis;

            edges[i] = {n1, n2, dis};
        }

        vector<vector<pair<int,int>>> adj_lst(V);

        for (int i = 0; i < E;i++){
            adj_lst[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj_lst[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }


        vector<int> res = dijikstra(V, E, src, adj_lst);
        for(auto k : res){
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}