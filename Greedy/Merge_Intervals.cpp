//56.
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_Intervals(int N,vector<vector<int>>&intervals){
    vector<vector<int>> op;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int currStart = intervals[0][0], currEnd = intervals[0][1];
    for (int j = 1; j < N;j++){
        if(currEnd < intervals[j][0]){
            op.push_back({currStart,currEnd});
            currStart = intervals[j][0];
            currEnd = intervals[j][1];
        }else{
            currEnd = max(currEnd,intervals[j][1]);

        }
    }
    op.push_back({currStart, currEnd});
    return op;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        vector<vector<int>> intervals;
        for (int i = 0; i < N;i++){
            int start, end;
            cin >> start >> end;

            intervals.push_back({start, end});
        }

        vector<vector<int>> res = merge_Intervals(N, intervals);
        for(auto k : res){
            for(auto m : k){
                cout << m << " ";
            }
            cout << endl;
        }
        cout << "---" << endl;
    }
    return 0;
}

// Approach :
// This is a classic grredy problem. First sort the array based on 0-index sorting & then use two variables to track current Start element & Current End element. 
// when the current End is less than next start tthen push the current iteration array without modification. Else change the current end to the max(current End,next start) & change current start to be the start of the array (current iteration)