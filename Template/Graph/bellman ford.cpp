#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define PLI pair<ll, int>

const int N = 3e5 + 9, mod = 1e9 + 7, INF = 1e9;

struct st{
    int a, b, cost;  
};

st edge[N];

int32_t main()
{
    int n, m; cin >> n >> m; // n vertex, m edges
    for(int i=0; i<m; i++) cin >> edge[i].a >> edge[i].b >> edge[i].cost;
    int s; // starter
    cin >> s;
    vector<int> d(n, INF);
    vector<int> p(n, -1); // parent
    
    d[s] = 0;
    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(auto e : edge){
            if(d[e.a] < INF){
                if(d[e.a] + e.cost < d[e.b]){
                   d[e.b] = d[e.a] + e.cost;
                   p[e.b] = e.a;
                   x = e.b;
                }
            }
        }
    }
    if(x == -1) cout << "No negative cycle from " << s;
    else{
        int y = x;
        // 找到距離src最近的點作為cycle的起點
        for (int i=0; i<n; ++i) y = p[y]; 
        
        vector<int> path;
        // order : y .... y
        for(int cur = y;; cur = p[cur]){
            path.push_back(cur);
            if(cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        
        cout<<"Negative cycle: ";
        for(int u:path)
            cout<<u<<' ';
    }
    return 0;
}