// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include<bits/stdc++.h>
using namespace std;

string long_prefix_common(int N,vector<string>& src){
    string frst = src[0];
    string res;
    for (int i = 0; i < frst.size();i++){
        bool pref = true;
        for (int j = 1; j < N;j++){
            if(src[j][i] != frst[i]){
                pref = false;
                break;
            }
        }
        if(pref){
            res.push_back(frst[i]);
        }else
            break;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> res(N);

        for (int i = 0; i < N;i++){
            string s;
            cin >> s;
            res[i] = s;
        }

        string ans = long_prefix_common(N, res);
        cout << ans << endl;
    }
    return 0;
}