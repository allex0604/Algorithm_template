#include <bits/stdc++.h>
using namespace std;

// compute phi(n) = n * (1 - 1 / p1) * (1 - 1 / p2) * ...
int phi(int n){
    int result = n;
    for(int i=2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    // n is prime
    if(n > 1)
        result -= result / n;
    return result;
}

// compute phi(1) ~ phi(n)
void phi_1_to_n(int n){
    vector<int> phi(n+1);
    for(int i=1; i <= n; i++)
        phi[i] = i;

    for(int i=2; i <= n; i++){
        // i is a prime
        if(phi[i] == i){
            for(int j=i; j<=n; j+=i)
                phi[j] -= phi[j] / i;
        }
    }

    for(int i=1; i<n; i++)
        cout<<"phi "<<i<<" = "<<phi[i]<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 10;
    cout << "Phi" << "(" 
         << n << ")" << " = "
         << phi(n) << endl;
    return 0;
}