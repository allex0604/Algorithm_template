#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PLI pair<ll, int>

const int N = 3e5 + 9, mod = 1e9 + 7, INF = 1e9;

int32_t main()
{
    int n , m; cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    for(int i=0; i<n; i++) d[i][i] = 0;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        cin >> d[u][v];
    }
    for(int k = 1; k <= n; k++){
        for(int src=1; src <= n; src++){
            for(int dst=1; dst <=n ;dst++){
                d[src][dst] = min(d[src][dst], d[src][k] + d[k][dst]);
            }
        }
    }
    return 0;
}
