#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
//vector and index
ll isANonDecending(vector<ll> as, ll i);
int main (){
    ll t; 
    cin >> t; 
    for (int i = 0; i < t; i++){
        ll n; 
        cin >> n;
        vector<ll> as(n);
        for(int j = 0; j < n; j++){
            cin >> as[j];
        }
        ll curmin = 100;
        for(int j = 0; j < n; j++){
            ll num = isANonDecending(as,j);
            if(num < curmin)
            curmin = num;
        }
        cout << curmin << '\n';

    }
    return 0;
}
ll isANonDecending(vector<ll> as, ll i) {
    
}