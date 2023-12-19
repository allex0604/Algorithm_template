#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PLI pair<ll, int>

const int N = 3e5 + 9, mod = 1e9 + 7;
vector<pair<int, int>> g[N];

vector<ll> dijkstra(int n, int s){
    const ll inf = 1e18;
    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
    // id from 1 to n
    vector<ll> d(n + 1, inf);
    
    pq.push({0, s});
    d[s] = 0;
    
    while(!pq.empty()){
        auto [dis, u] = pq.top();
        pq.pop();
        // 在run到此輪時已經再次更新了,更新就代表有更短的距離
        if(dis != d[u]) continue;
        for(auto [nxt, w] : g[u]){
            if(d[u] + w < d[nxt]){
                d[nxt] = d[u] + w;
                pq.push({d[nxt], nxt});
            }
        }
    }
    return d;
}


int32_t main()
{
    
    return 0;
}