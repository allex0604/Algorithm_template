#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9 + 7;

// compute x^n
ll fast_pow(ll x, ll n){
    ll base = x % mod;
    ll ans = 1;

    while(n){
        if(n & 1) ans =ans * base % mod;
        base = base * base % mod;
        n >>= 1;
    }

    return ans;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x = 2, n = 15;
    cout << fast_pow(x, n) << '\n';
    return 0;
}
