#include <bits/stdc++.h>
using namespace std;
//bullshit
typedef long long ll; 
int main (){
    ll T; 
    cin >> T; 
    for(ll i = 0; i < T; i++){
        string S; 
        ll N; 
        cin >> N;
        cin >> S;
        vector<ll> index1;
        vector<ll> index0;
        for(ll j = 1; j <= N; j ++){
            if(S[j-1] == '1'){
                index1.push_back(j);
            }else{
                index0.push_back(j);
            }
        }
        //same nule vrnem 0 
        if(index1.size() == 0){
            cout << 0 << '\n';
        }
        //liho stevilo 0  in ničk manj kot 1 obrem 0 
        else if((index0.size()%2 != 0) && (index0.size() < index1.size())){
            cout << index0.size() << " \n";
            for(ll j = 0; j < (ll) index0.size(); j++)
                cout << index0[j] << " ";
            cout << '\n';
        }
        //sodo stevilo 1 obrnem 1
        else if(index1.size()%2 == 0) {
            cout << index1.size() << " \n";
            for(ll j = 0; j < (ll) index1.size(); j++)
                cout << index1[j] << " ";
            cout << '\n';
        }
        //ponovno obrnem nič v primeru sodih - sem pridejo tisti primerei v katerih je bilo enk manj kot 0 a jih je bilo liho ------- fuck you
        else if(index0.size()%2 != 0){
              cout << index0.size() << " \n";
            for(ll j = 0; j < (ll) index0.size(); j++)
                cout << index0[j] << " ";
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }    
    }
    return 0;
}
