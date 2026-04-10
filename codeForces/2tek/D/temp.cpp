#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main (){
    ll t; 
    cin >> t; 
    for (ll i = 0; i < t; i++){
        ll n,x,y; 
        cin >> n >> x >> y; 

        vector<ll> all(n);
        for(ll j = 0; j < n; j++)
            cin >> all[j];

        list<ll> L;
        list<ll> M; 
        list<ll> R;

        for(ll j = 0; j < n; j++){
            if(j < x) 
                L.push_back(all[j]);
            else if(j < y) 
                M.push_back(all[j]);
            else 
                R.push_back(all[j]);
        }

        // združim L in R za sortiranje 
        list<ll> O;
        O.insert(O.end(), L.begin(), L.end());
        O.insert(O.end(), R.begin(), R.end());

        // sortiramo elemente izven M
        O.sort();

        // Razdruzitev 
        auto it = O.begin();
        list<ll> nL; 
        list<ll> nR; 

        for(int i = 0; i < x && it != O.end(); i++, it++)
            nL.push_back(*it);

        while(it != O.end()){
            nR.push_back(*it);
            it++;
        }

        // naredimo dve možnosti: M normalen in obrnjen
        vector<ll> ans1, ans2;

        // možnost 1
        for(auto el : nL) ans1.push_back(el);
        for(auto el : M) ans1.push_back(el);
        for(auto el : nR) ans1.push_back(el);

        // možnost 2 (obrnjeni M)
        list<ll> Mr;
        for (auto rit = M.rbegin(); rit != M.rend(); ++rit){
            Mr.push_back(*rit);
        }
        M.reverse();
        for(auto el : nL) ans2.push_back(el);
        for(auto el : M) ans2.push_back(el);
        for(auto el : nR) ans2.push_back(el);

        // izberemo manjšega
        if(ans2 < ans1) ans1 = ans2;

        for(auto el : ans1) cout << el << " ";
        cout << "\n";
    }
    return 0;
}