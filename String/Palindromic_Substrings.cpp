// 647
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

#include<bits/stdc++.h>
using namespace std;

int palinDrome_check(int i,int j,string s,int N){
    int cnt = 0;
    while(i >= 0 && j < N && s[i] == s[j]){
        cnt++;
        i--;
        j++;
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int N = s.size();

        int res = 0;
        for (int i = 0; i < N;i++){
            int odd = palinDrome_check(i, i, s, N);
            int eve = palinDrome_check(i, i + 1, s, N);
            cout << odd << " " << eve << endl;
            res += (odd + eve);
        }

        cout << res << endl;
    }
    return 0;
}