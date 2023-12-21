#include<bits/stdc++.h>
using namespace std;

/*
    g : 紀錄u到v有無edge,包含edge id
    color 紀錄vertex狀態 ==> 0 : 沒遇過 , 1 : 已經遇到但還沒結束, 2 : 結束
    par : parent of each vertex
    e_id : 記錄此點的in-degree edge
*/
vector<vector<pair<int, int>>> g;
vector<int> color, par, e_id, cycle;
bool dfs(int u){
    color[u] = 1;
    for(auto [v, id] : g[u]){
        if(v != par[u]){
            if(color[v] == 0){
                par[v] = u;
                e_id[v] = id;
                if(dfs(v)) return 1;
            }else if(color[v] == 1){
            // find cycle
                cycle.push_back(id);
                for(int x=u; x != v; x = par[x])
                    cycle.push_back(e_id[x]);
                return 1;
            }        
        }
    }
    color[u] = 2;
    return 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    color = vector<int>(n+1, 0), par = vector<int>(n+1), e_id = vector<int>(n+1);
    g = vector<vector<pair<int, int>>>(n+1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ++u; ++v;
        g[u].push_back({v, i});
    }
    
    for(int u=1; u<=n; u++){
        if(color[u] == 0 && dfs(u)){
            cout<<cycle.size()<<endl;
            // output each edge in cycle
            for(auto x : cycle) cout<<x-1<<endl;
            return 0;
        }
    }
    // no cycle
    cout<<-1<<endl;
    return 0;
}