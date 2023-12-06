#include<bits/stdc++.h>
using namespace std;



// diff : 差分數組
// a[1] = diff[1]
// a[2] = diff[1] + diff[2]
// a[m] = diff[1] + ... + diff[m]

/*
    BIT tree結合差分數組 
    ==> 实现 O(log n) 的區間修改
    ==>區間修改的意思 : 區間內每一個都+-x 
    query [a1,..., am] 
    = 也就是a[1] + ... + a[m]
    = ∑(m-i+1)*diff[i]
    = (m+1)∑diff[i] - ∑i*diff[i]

    query [aL, ..., aR] == [a1,... aR] - [a1, .., aL-1] 

    array M : diff[i] 的 BIT tree
    array A : i*diff[i] 的 BIT tree

    假設a[l] 到 a[r] 增加 val
    ==> diff[l] += val , diff[r+1] -= val
    ==> 也就代表
*/

#define LL long long

struct BIT
{
    // diff[1] ~ diff[m]
    vector<LL> M, A;
    int _n;
    BIT(int n) {
        _n = n; 
        M.assign(n+1, 0);
        A.assign(n+1, 0);
    }

    long long query(int i){
        long long mul = 0, add = 0;
        int st = i;
        for(; i > 0; i -= (i & -i)){
            mul += M[i];
            add += A[i];
        }
        return (st + 1) * mul - add;
    }

    long long query(int l, int r){
        return query(r) - query(l - 1);
    }

    void upd(int i, LL val){
        for(int iv = i * val; i <= _n; i += (i & -i)){
            M[i] += val;
            A[i] += iv;
        }
    }

    void upd(int i, int r, LL val){
        upd(i, val);
        upd(r+1, -val);
    }
};

int32_t main() {

  return 0;
}
