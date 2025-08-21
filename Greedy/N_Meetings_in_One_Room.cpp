// Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.


// Examples:
// Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]

// Output : 4

// Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

// Input : Start = [10, 12, 20] , End = [20, 25, 30]

// Output : 1

// Explanation : Given the start and end time, only one meeting can be held in meeting room.

#include<bits/stdc++.h>
using namespace std;

int n_meetings_in_one_room(vector<vector<int>>& arr,int N){
    int end = arr[0][1],cnt = 1;

    for (int i = 1; i < N;i++){
        if(end < arr[i][0]){
            cnt++;
            end = arr[i][1];
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

        vector<int> start(N), end(N);
        for (int i = 0; i < N;i++){
            cin >> start[i];
        }
        for (int i = 0; i < N;i++){
            cin >> end[i];
        }

        vector<vector<int>> combined(N, vector<int>(2));

        for (int i = 0; i < N;i++){
            combined[i] = {start[i], end[i]};
        }

        sort(combined.begin(), combined.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int op = n_meetings_in_one_room(combined, N);
        cout << op << endl;
    }
    return 0;
}