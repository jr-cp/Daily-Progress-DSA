// Given an array of N intervals in the form of (start[i], end[i]), where start[i] is the starting point of the interval and end[i] is the ending point of the interval, 
//return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping.

// Examples:
// Input : Intervals = [ [1, 2] , [2, 3] , [3, 4] ,[1, 3] ]
// Output : 1
// Explanation : You can remove the interval [1, 3] to make the remaining interval non overlapping.

// Input : Intervals = [ [1, 3] , [1, 4] , [3, 5] , [3, 4] , [4, 5] ]
// Output : 2

// Explanation : You can remove the intervals [1, 4] and [3, 5] and the remaining intervals becomes non overlapping

#include<bits/stdc++.h>
using namespace std;

int non_overlapping_intervals(vector<vector<int>>& intervals,int N){
    int currEnd = intervals[0][1],cnt = 0;

    for (int i = 1; i < N;i++){
        if(currEnd > intervals[i][0]){
           cnt++;
        }
        else
            currEnd = intervals[i][1];
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
    
        vector<vector<int>> intervals(N, vector<int>(2));
    
        for (int i = 0; i < N;i++){
            int frst, scnd;
            cin >> frst >> scnd;
    
            intervals[i] = {frst, scnd};
        }
    
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
       
        int res = non_overlapping_intervals(intervals, N);
        cout << res << endl;
    }

    return 0;
}