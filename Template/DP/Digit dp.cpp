#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;

ll a, b, d, k;
ll dp[20][20][2];
vector<int> v;

int call(int p, int cnt, int f){
    if(cnt > k) return 0;
    if(p == -1){
        if(cnt == k) return 1;
        else return 0;
    }

    if(dp[p][cnt][f] != -1)
        return dp[p][cnt][f];

    ll ret = 0;
    int LMT;
    if(f == 0){
        LMT = v[p];
    }else{
        LMT = 9;
    }

    for(int i=0; i<=LMT; i++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && i < LMT) nf = 1;
        if(i == d) ncnt++;
        ret = (ret + call(p-1, ncnt, nf)) % mod; 
    }

    return dp[p][cnt][f] = ret;
}

int solve(ll n){
    if(n == 0) return 0;
    v.clear();
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }

    memset(dp, -1, sizeof(dp));
    
    return call(v.size()-1, 0, 0);
}

int32_t main(){
    cin >> a >> b >> d >> k;
    ll res = (solve(b) - solve(a-1) + mod) % mod;
    cout << res << endl;
    return 0;
}