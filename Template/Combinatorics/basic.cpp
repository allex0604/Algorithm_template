#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9+7, maxn = 1e3 + 5;

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

struct combi{
  // facts[n] = n! , finvs[n] = 1 / n!
  int n; vector<ll> facts, finvs;
  combi(int _n): n(_n), facts(_n + 1), finvs(_n + 1){
    facts[0] = facts[1] = 1;
    for(int i = 2; i <= n; i++) facts[i] = facts[i-1] * i % mod;
    finvs[n] = fast_pow(facts[n], mod - 2);
    for(int i = n-1; i >= 0; i--) finvs[i] = finvs[i+1] * (i + 1) % mod;
  }
  inline int fact(int n) { return facts[n]; }
  inline int finv(int n) { return finvs[n]; }
  // C(n, k)
  inline int ncr(int n, int k) { return n < k or k < 0 ? 0 : (facts[n] * finvs[k]) % mod * finvs[n-k] % mod; }
  // P(n, k)
  inline int npr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[n - k] % mod; }
  // H(n, k) = C(n+k-1, k)
  inline int nhr(int n, int k) { return n < k or k < 0 ? 0 : ncr(n+k-1, k); }
};

int main()
{
    combi C(maxn);
    cout<<C.ncr(10, 2)<<endl;

    return 0;
}