#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long  binary_exponentition(long long base,long long pow){
    if(pow == 0)
        return 1;
    if(pow == 1)
        return base % mod;
    else{
        if(pow % 2 == 1){
            return (base * binary_exponentition(base, pow - 1)) % mod ;
        }else{
            return binary_exponentition(base % mod * base % mod, pow / 2);
        }
    }
}



int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long res;
        if(N % 2 == 1){
            res = binary_exponentition(5, (N / 2) + 1) * binary_exponentition(4, (N / 2));
        }else{
            res = binary_exponentition(5, (N / 2)) * binary_exponentition(4, (N / 2));
        }

        cout << (res % mod) << endl;
    }
    return 0;
}