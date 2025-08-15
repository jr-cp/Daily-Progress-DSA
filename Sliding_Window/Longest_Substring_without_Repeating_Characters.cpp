// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int N = s.size(),maxLen = 1;
        int l = 0,r = 0;

        unordered_set<char> vMap;
        for (; r < N;r++){
            if(vMap.count(s[r])){
                while(vMap.count(s[r])){
                    vMap.erase(s[l]);
                    l++;
                }
            }
            vMap.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        cout << maxLen << endl;
    }    
    return 0;
}