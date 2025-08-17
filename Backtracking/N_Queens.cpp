// he challenge of arranging n queens on a n × n chessboard so that no two queens attack one another is known as the "n-queens puzzle."
// Return every unique solution to the n-queens puzzle given an integer n. The answer can be returned in any sequence.
// Every solution has a unique board arrangement for the placement of the n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.
// Examples:
// Input : n = 4
// Output : [[".Q.." , "...Q" , "Q..." , "..Q."] , ["..Q." , "Q..." , "...Q" , ".Q.."]]
// Explanation : There are two possible combinations as shown below.
// Input : n = 2

// Output : [ [] ]

// Explanation : There is no possible combination for placing two queens on a board of size 2*2.

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int N,int row,int col,vector<string>& board){
    int r = row, c = col;

    // Upper left diagonal Check
    while(r >= 0 && c >= 0){
        if(board[r][c] == 'Q')
            return false;
        r--;
        c--;
    }

    r = row, c = col;

    // Left Side Check
    while(c >= 0){
        if(board[row][c] == 'Q')
            return false;
        c--;
    }

    r = row, c = col;

    // Lower Left Diagonal Check
    while(r < N && c >= 0){
        if(board[r][c] == 'Q')
            return false;
        r++;
        c--;
    }
    return true;
}

void n_queens(int N,int col,vector<string>& board,vector<vector<string>>& res){
    if(col == N){
        res.push_back(board);
        return;
    }

    for (int row = 0; row < N;row++){
        if(isSafe(N,row,col,board)){
            board[row][col] = 'Q';
            n_queens(N, col + 1, board, res);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> board(N, string(N, '.'));
        vector<vector<string>> res;

        n_queens(N, 0, board, res);

        for(auto k : res){
            for(auto s : k){
                cout << s << endl;
            }
            cout << "-------------------" << endl;
        }
        cout << endl;
    }
    return 0;
}

