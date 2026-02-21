#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
struct Test{
    ll M; 
    ll H;
    ll RT; 
    vector<int> bullets;
};
ll output(Test t);
int main (){
    int T; 
    cin >> T; 
    for(int i = 0; i < T; i++){
        Test t;
        cin >> t.M >> t.H >> t.RT;
        for(int j = 0; j < t.M; j++){
            int temp; 
            cin >> temp;
            t.bullets.emplace_back(temp);
        }
        cout << output(t) << '\n';
    }
    return 0;
}
ll output (Test t){ 
    ll tt = 0; //total time
    ll dd = 0; // damage dealt
    ll bd = 0; // bigest deamage index
    for (int i = 0; i < t.bullets.size(); i++){
        if(t.bullets[bd] < t.bullets[i]){
            bd = i;
        }
    }
    while(t.H > dd){
        
    }
    return tt;
}
