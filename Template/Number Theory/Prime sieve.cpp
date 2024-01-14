#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

// SPF[] that store smallest prime factor of number

vector<int> SPF(N);
vector<int> primes;

void sieve(){
    bool p[N];
    memset(p, true, sizeof(p));
    for(int i=2; i < N; i++){
        if(SPF[i] == 0) SPF[i] = i, primes.push_back(i);
        int sz = primes.size();
        for(int j = 0; j < sz && i * primes[j] < N && primes[j] <= SPF[i]; j++)
            SPF[i * primes[j]] = primes[j];
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cout<<primes.size();
}