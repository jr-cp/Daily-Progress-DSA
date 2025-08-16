// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

vector<int> dir{0, 1, 0, -1, 0};

void dfs(int i,int j,int M,int N,vector<vector<char>>& env){
    if(i < 0 || i >= M || j < 0 || j >= N || env[i][j] == '0')
        return;

    env[i][j] = '0';

    for (int k = 0; k < 4;k++){
        int newI = dir[k] + i, newJ = dir[k + 1] + j;
        dfs(newI, newJ, M, N, env);
    }
}


int main()
{
    int T;
    cin >> T;
    while (T--) {
        int M,N;
        cin >> M >> N;

        vector<vector<char>> env(M, vector<char>(N));

        for (int i = 0; i < M;i++){
            for (int j = 0; j < N;j++){
                cin >> env[i][j];
            }
        }

        int cnt = 0;

        for (int i = 0; i < M;i++){
            for (int j = 0; j < N;j++){
                if(env[i][j] == '1'){
                    cnt++;
                    dfs(i, j, M, N, env);
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}