#include<iostream>
#include<vector>
using namespace std;

void merge(int low,int mid,int high,vector<int>&arr){
    vector<int> new_arr(high + 1);
    
    int l = low,r = mid + 1,curr = 0;

    while(l <= mid && r <= high){
        if(arr[l] < arr[r]){
            new_arr[curr] = arr[l];
            l++;
        }else{
            new_arr[curr] = arr[r];
            r++;
        }
        curr++;
    }

    while(l <= mid){
        new_arr[curr] = arr[l];
        l++;
        curr++;
    }

    while(r <= high){
        new_arr[curr] = arr[r];
        r++;
        curr++;
    }

    for (int i = low; i <= high;i++){
        arr[i] = new_arr[i - low];
    }

}

void divide(int low,int high,vector<int>&arr){
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    
    divide(low, mid, arr);
    divide(mid + 1, high, arr);

    merge(low, mid, high, arr);
}
int main(){
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> nums(N);

        for (int i = 0; i < N;i++){
            int n;
            cin >> n;
            nums[i] = n;
        }

        int low = 0, high = N - 1;
        for(auto k : nums){
            cout << k << " ";
        }
        divide(low, high, nums);

        for(auto k : nums){
            cout << k << " ";
        }
    }
}