// Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval, the array represents non-overlapping intervals 
//sorted in ascending order by start[i].  Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval,
// merge newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].
// Return Intervals after the insertion of newInterval.

// Examples:
// Input : Intervals = [ [1, 3] , [6, 9] ] , newInterval = [2, 5]

// Output : [ [1, 5] , [6, 9] ]

// Explanation : After inserting the newInterval the Intervals array becomes [ [1, 3] , [2, 5] , [6, 9] ].

// So to make them non overlapping we can merge the intervals [1, 3] and [2, 5].

// So the Intervals array is [ [1, 5] , [6, 9] ].

// Input : Intervals = [ [1, 2] , [3, 5] , [6, 7] , [8,10] ] , newInterval = [4, 8]


// Output : [ [1, 2] , [3, 10] ]



// Explanation : The Intervals array after inserting newInterval is [ [1, 2] , [3, 5] , [4, 8] , [6, 7] , [8, 10] ].

// We merge the required intervals to make it non overlapping.

// So final array is [ [1, 2] , [3, 10] ].

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> insert_Interval(vector<pair<int, int>> intervals, int N){

    vector<pair<int, int>> res;
    int currStart = intervals[0].first, currEnd = intervals[0].second;

    for (int i = 1; i < N ;i++){
        if(currEnd < intervals[i].first){
            res.push_back({currStart, currEnd});
            currStart = intervals[i].first;
            currEnd = intervals[i].second;
        }else{
            currEnd = max(currEnd, intervals[i].second);
        }
    }
    res.push_back({currStart, currEnd});
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> intervals(N);
        pair<int, int> newInterval;

        for (int i = 0; i < N;i++){
            int frst, scnd;
            cin >> frst >> scnd;

            intervals[i] = {frst, scnd};

        }

        cin >> newInterval.first >> newInterval.second;

        intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

        vector<pair<int, int>> res = insert_Interval(intervals, N+1);

        for(auto k : res){
            cout << k.first << " " << k.second << endl;
        }
        cout << "---------" << endl;
    }
    return 0;
}

// Approach : First add the NewInterval to be inserted to the Interval array and sort it. I used lambda function to learn it but it can be sorted using normal sort function.
// Then do the merge intervals problem for this and get the answer