#include<bits/stdc++.h>
using namespace std;
/*
    g[u][i] = v ==> u -> v
    done[u] = 目前走完vertex u幾條邊了
    vis[i] = 確認有無強連通
    in[u] ==> indegree of u , out[u] ==> outdegree of u
    ans = euler path(cycle)
    euler path : graph恰好有一個vertex的indegree - outdegree = 1且
                 graph恰好有一個vertex的outdegree - indegree = 1
    euler cycle : 此graph連通(connected)且所有vertex的indegree = outdegree
*/
vector<vector<int>> g;
vector<bool> vis;
vector<int> ans, done, in, out;
void dfs(int u){
    vis[u] = 1;
    while(done[u] < g[u].size()) dfs(g[u][done[u]++]);
    ans.push_back(u);
}

bool solve(int n, int m){
    int cnt1 = 0, cnt2 = 0, root = 0;
    for(int i = 1; i <= n; i++){
        if(abs(out[i] - in[i]) > 1) return 0;
        else if(in[i] - out[i] == 1) cnt1++;
        else if(out[i] - in[i] == 1) cnt2++, root = i;
    }
    //if(cnt1 > 0 || cnt2 > 0) return 0; // without euler circuit
    if(!(cnt1 == 0 && cnt2 == 0) && !(cnt1 == 1 && cnt2 == 1)) return 0; // without euler path
    if(root == 0){
        for(int i=1; i<=n; i++) if(out[i]) root = i;
        if(root == 0) return 1; // empty graph
    }    
    vis = vector<bool>(n+1, 0);
    done = vector<int>(n+1, 0);
    dfs(root);
    for(int i=1; i<=n; i++) if(!vis[i]) return 0; // connectivity
    reverse(ans.begin(), ans.end());
    return 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    g = vector<vector<int>>(n + 1);
    in = vector<int>(n+1, 0); out = vector<int>(n+1, 0);
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        in[v]++, out[u]++;
    } 
    if(solve(n, m)){
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        ans.clear();
    }
    return 0;
}