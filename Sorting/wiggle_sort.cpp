#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int>& arr, bool reverse) {
    int l = low, r = mid + 1;
    vector<int> tempArr;

    if (reverse) {
        while (l <= mid && r <= high) {
            if (arr[l] > arr[r]) {
                tempArr.push_back(arr[l]);
                l++;
            } else {
                tempArr.push_back(arr[r]);
                r++;
            }
        }
    } else {
        while (l <= mid && r <= high) {
            if (arr[l] < arr[r]) {
                tempArr.push_back(arr[l]);
                l++;
            } else {
                tempArr.push_back(arr[r]);
                r++;
            }
        }
    }

    while (l <= mid) {
        tempArr.push_back(arr[l]);
        l++;
    }
    while (r <= high) {
        tempArr.push_back(arr[r]);
        r++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = tempArr[i - low];
    }
}
void divide(int low, int high, vector<int>& arr, bool reverse) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    divide(low, mid, arr, reverse);
    divide(mid + 1, high, arr, reverse);

    merge(low, mid, high, arr, reverse);
}

vector<int> wiggle_sort_II(int N,vector<int>&nums){
    if (N <= 2) return nums;

    divide(0, N - 1, nums, false);

    vector<int> odd(nums.begin(), nums.begin() + (N + 1) / 2);
    vector<int> eve(nums.begin() + (N + 1) / 2, nums.end());

    int o = odd.size() - 1;
    int e = eve.size() - 1;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            nums[i] = odd[o--];   
        } else {
            nums[i] = eve[e--];   
        }
    }

    return nums;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> nums(N);

        for (int i = 0; i < N;i++){
            cin >> nums[i];
        }

        vector<int> res = wiggle_sort_II(N, nums);

        for(auto k : res){
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}