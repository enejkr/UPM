#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
struct node{
    ll org; //index vozlišča 
    unordered_set<ll> Zd; //vsi el na tem mestu
};
//& pointer 
void preform1(ll L, ll R,vector<node>& P);
void preform2(ll L, ll R,vector<node> P);

int main(){
    ll N,Q; 
    cin >> N >> Q;
    vector<node> P(N);
    for (ll i = 0; i < (ll) P.size(); i++){
        node tempNode;
        cin >> tempNode.org; 
        tempNode.Zd.insert(tempNode.org);
        P[i] = tempNode;
    }
    for(ll i = 0; i < Q; i++){
        ll T, L, R; 
        cin >> T >> L >> R;
        if(T == 1){
            //zdriži elemente med L in R v P in jih shrnai v vakem nodeu umes
            preform1(L,R,P);
        }
        else {
            //izpiši stevilo unikatnih elemntoc med združitvami na nodeih L - R 
            preform2(L,R,P);
        }
    }
}
void preform1(ll L, ll R,vector<node>& P){
    unordered_set<ll> newZd;
    for(int i = L; i <= R; i++){
        for(auto el: P[i-1].Zd){
            newZd.insert(el);
        }
    }
    for(int i = L; i <= R; i++){
        // cout << "elementi prej: \n ";
        // for (auto e: P[i-1].Zd)
        //     cout << e << ", ";
        P[i-1].Zd = newZd;
        
        // cout << "elementi po: \n ";
        // for (auto e: P[i-1].Zd)
        //     cout << e << ", ";
    }
}
void preform2(ll L, ll R,vector<node> P){
    unordered_set<string> newZd;
    for(int i = L; i <= R; i++){
        string hash = "";
        for (auto el: P[i-1].Zd){
            cout << " element " << el;
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
//  {3,5,2}, {3,5,2}, {3,5,2}, {1}, {4} 
//  po 1 3 4
//  {3,5,2}, {3,5,2},{3,5,2,1}, {3,5,2,1}, {4} 
//
// 5 4
// 3 5 2 1 4
// 1 1 3 
// 2 1 4        - 2
// 1 3 4
// 2 3 5
