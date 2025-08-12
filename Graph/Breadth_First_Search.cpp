#include<bits/stdc++.h>
using namespace std;



int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges{{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<vector<int>> adj_lst(N);

    for (int i = 0; i < N;i++){
        adj_lst[i] = edges[i];
    }

    queue<int> que;
    unordered_set<int> visited;

    vector<int> res;

    que.push(0);
    visited.insert(0);

    while(!que.empty()){
        int fr = que.front();
        que.pop();
        res.push_back(fr);
        
        for(auto nd : adj_lst[fr]){
            if(!visited.count(nd)){
                que.push(nd);
                visited.insert(fr);
            }
        }
    }

    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}