#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main (){
    ll t;
    cin >> t;

    for(ll i = 0; i < t; i++){
        ll n; 
        cin >> n; 
        vector<ll> food(n); 
        for(ll j = 0; j < n; j++){
            cin >> food[j];
        }
        unordered_map<ll, ll> winners; 
        for(ll j = 0; j < n; j++){
            vector<ll> temp = food;   
            ll total = 0;
            for(ll x : temp) total += x;   
            ll curPlayer = j;
            while(total > 0){
                if(temp[curPlayer] > 0){
                    temp[curPlayer]--;
                    total--;
                    if(total == 0){ 
                        winners[curPlayer] = 1;
                        break;
                    }
                }
                curPlayer = (curPlayer + 1) % n;
            }
        }
        cout << winners.size() << "\n";
    }

    return 0;
}