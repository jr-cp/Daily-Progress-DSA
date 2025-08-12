// Example 1:

// Input: num = 3749

// Output: "MMMDCCXLIX"

// Explanation:

// 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC as 500 (D) + 100 (C) + 100 (C)
//   40 = XL as 10 (X) less of 50 (L)
//    9 = IX as 1 (I) less of 10 (X)
// Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
// Example 2:

// Input: num = 58

// Output: "LVIII"

// Explanation:

// 50 = L
//  8 = VIII
// Example 3:

// Input: num = 1994

// Output: "MCMXCIV"

// Explanation:

// 1000 = M
//  900 = CM
//   90 = XC
//    4 = IV

#include<bits/stdc++.h>
using namespace std;

int main()
{

#include <unordered_map>
#include <string>
using namespace std;

vector<pair<int, string>> cMap{
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

int num;
cin >> num; // 3749;

string res = "";

for (auto &n : cMap)
{
    cout << n.first << " " << n.second << endl;
    if(num == 0)
        break;
    while (num >= n.first)
    {
        res += n.second;
        num -= n.first;
        cout << num << endl;
    }
}

    cout << res;

    return 0;
}