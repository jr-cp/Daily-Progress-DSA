// Numbers ascending Characters descending

#include<bits/stdc++.h>
using namespace std;

void merge(int low,int mid,int high,vector<int> &arr){
    vector<int> newArr;
    int l = low, r = mid + 1;

    while(l <= mid && r <= high){
        if(arr[l] < arr[r]){
            newArr.push_back(arr[l]);
            l++;
        }else{
            newArr.push_back(arr[r]);
            r++;
        }
    }

    while(l <= mid){
        newArr.push_back(arr[l]);
        l++;
    }
    while(r <= high){
        newArr.push_back(arr[r]);
        r++;
    }

    for (int i = low; i <= high;i++){
        arr[i] = newArr[i - low];
    }
}

void divide(int low,int high,vector<int> &arr){
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    divide(low, mid, arr);
    divide(mid + 1, high, arr);

    merge(low, mid, high, arr);
}

void rev_mergeC(int low,int mid,int high,vector<char> &arr){
    vector<char> newArr;
    int l = low, r = mid + 1;

    while(l <= mid && r <= high){
        if(arr[l] > arr[r]){
            newArr.push_back(arr[l]);
            l++;
        }else{
            newArr.push_back(arr[r]);
            r++;
        }
    }

    while(l <= mid){
        newArr.push_back(arr[l]);
        l++;
    }
    while(r <= high){
        newArr.push_back(arr[r]);
        r++;
    }

    for (int i = low; i <= high;i++){
        arr[i] = newArr[i - low];
    }
}

void rev_divideC(int low,int high,vector<char> &s){
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    rev_divideC(low, mid, s);
    rev_divideC(mid + 1, high, s);

    rev_mergeC(low, mid, high, s);
}

vector<int> mySolution(){

}


int main()
{
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;

        vector<int> num;
       vector<char> chars;

        for(char k : str){
            if(k - '0' >= 0 && k - '0' <= 9){
                num.push_back(k - '0');
            }else{
                chars.push_back(k);
            }
        }

        divide(0, (int)num.size() - 1, num);
        rev_divideC(0, (int)chars.size() - 1, chars);

        

        int pn = 0, pc = 0;
        string res = "";

        for (int j = 0; j < (int)str.size();j++){
            if(str[j] - '0' >= 0 && str[j] - '0' <= 9 ){
                res += (num[pn] + '0');
                pn++;
            }else{
                res += chars[pc];
                pc++;
            }
        }

        cout << res << endl;
        }
    return 0;
}