#include<bits/stdc++.h>
using namespace std;


const int N = 10;

struct ST{
    // lazy[i] == 0 : 表示不需要更新
    // lazy[i] != 0 : 需要更新 
    int t[4 * N], lazy[4 * N];
    static const int inf = 1e9;
    ST(){
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }

    // 節點 id 的整個區間要加上 x
    void push(int id, int l, int r){
        // 此node不需要更新
        if(lazy[id] == 0) return;
        // 因為整個區間都加x,最大值也會+x
        t[id] += lazy[id];
        // 此node為non-leaf,因為此node已經更新,將lazy轉移至child
        if(l != r){
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        // 因為更新完了 ==> reset
        lazy[id] = 0;
    }

    void build(vector<int> &a, int id, int l, int r){
        if(l == r){
            t[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);

        t[id] = max(t[2 * id], t[2 * id + 1]);
    }

    // 要update的是區間[gl, gr]的值都加x
    void upd(int id, int l, int r, int gl, int gr, int x){
        if(l > gr || r < gl)  return;
        if(l >= gl && r <= gr){
            lazy[id] += x;
            push(id, l, r);
            return;
        } 

        push(id, l, r);
        int mid = (l + r) / 2;
        upd(2 * id, l, mid, gl, gr, x);
        upd(2 * id + 1, mid + 1, r, gl, gr, x);

        t[id] = max(t[2 * id], t[2 * id + 1]);  
    }

    // 搜尋[gl, gr]內的值
    int query(int id, int l, int r, int gl, int gr){
        // 每經過一個node就看是否還未更新
        push(id, l, r);
        if(l > gr || r < gl) return -inf;
        if(l >= gl && r <= gr) return t[id];
        int mid = (l + r) / 2;
        int L = query(2 * id, l, mid, gl, gr);
        int R = query(2 * id + 1, mid + 1, r, gl, gr);
        return max(L, R);
    }
}t;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = a.size();
    ST s;
    s.build(a, 1, 0, n-1);
    cout<<s.query(1, 0, n-1, 3, 7)<<endl;
    s.upd(1, 0, n-1, 3, 7, 5);
    cout<<s.query(1, 0, n-1, 3, 9)<<endl;
    return 0;
}