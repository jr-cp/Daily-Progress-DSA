#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);

    int prof = 0;

    for (int i = 0; i < N;i++){
        cin >> nums[i];
    }

        for (int i = 0; i < N - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                prof += (nums[i + 1] - nums[i]);
        }

    

    cout << prof << endl;
    return 0;
}