#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
struct node{
    ll org; //index vozlišča 
    unordered_set<ll> Zd; //vsi el na tem mestu
};
//& pointer 
void preform1(ll L, ll R,unordered_map<ll, unordered_set<ll>>& P);
void preform2(ll L, ll R, unordered_map<ll, unordered_set<ll>>& P);

int main(){
    ll N,Q; 
    cin >> N >> Q;
    unordered_map<ll, unordered_set<ll>> P;
    //vector<node> P(N);
    for (ll i = 0; i < N; i++){
        ll key;
        cin >> key; 
        unordered_set<ll> value;
        value.insert(key);
        P[key] = value;
    }
    cout << "P: \n";
    for (auto el: P) {
        cout << el.first << ", ";
    }
    for(ll i = 0; i < Q; i++){
        ll T, L, R; 
        cin >> T >> L >> R;
        if(T == 1){
            //zdriži elemente med L in R v P in jih shrnai v vakem nodeu umes
            cout << "preforming 1\n" ;
            preform1(L,R,P);
        }
        else {
            //izpiši stevilo unikatnih elemntoc med združitvami na nodeih L - R 
            cout << "preforming 2\n" ;
            preform2(L,R,P);
        }
    }
}
void preform1(ll L, ll R,unordered_map<ll, unordered_set<ll>>& P){
    cout << "in preform 1 \n" ;
    unordered_set<ll> newZd;
    for(ll i = L; i <= R; i++){
        cout << "izpisujem elemente P " << i << "\n";
        for(auto el: P[i]){
            cout << el << "\n";
            newZd.insert(el);
        }
    }
    for(ll i = L; i <= R; i++){
        // cout << "elementi prej: \n ";
        // for (auto e: P[i])
        //     cout << e << ", ";
        P[i]= newZd;
        // cout << "elementi po: \n ";
        // for (auto e: P[i-1].Zd)
        //     cout << e << ", ";
    }
}
void preform2(ll L, ll R,unordered_map<ll, unordered_set<ll>>& P){
    unordered_set<string> newZd;
    for(int i = L; i <= R; i++){
        string hash = "";
        for (auto el: P[i]){
            cout << " element " << el << '\n';
            hash += to_string(el);
        }

        sort(hash.begin(), hash.end());
        cout << "hash vmes " << hash << "\n";
        newZd.insert(hash);
    }
    cout<<"odgovor: " << newZd.size() << "\n";
}
// {3}{5}{2}{1}{4}
//  po 1 1 3
//     3        5         2     1    4
//  {3,5,2}, {3,5,2}, {3,5,2}, {1}, {4} 
//  po 1 3 4
//     3        5         2          1      4
//  {3,5,2}, {3,5,2},{3,5,2,1}, {3,5,2,1}, {4} 
//
// 5 4
// 3 5 2 1 4
// 1 1 3 
// 2 1 4        - 2
// 1 3 4
// 2 3 5
