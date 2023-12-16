#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

unordered_map<int, vector<pair<int, int>>> adj;

// 0-1 bfs
int zero_one_bfs(){
    vector<int> dist(N, INT_MAX);
    deque<int> dq;
    
    dist[0] = 0;
    dq.push_back(0);

    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();
        // if asking single destination
        if(v == N-1) return dist[v];
        for(auto &edge : adj[v]){
            int u = edge.first;
            int w = edge.second;
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
                if(w == 1)
                    dq.push_front(u);
                else
                    dq.push_front(u);
            }
        }
    }
}