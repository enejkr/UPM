#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int main (){
    ll N, leftPos, rightPos; 
    ll temp;
    ll counter = 0;
    vector<int> V;
    ll R = 0; 
    ll L = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> temp; 
        V.emplace_back(temp);
    }
    leftPos = 0; 
    rightPos = N-1;
    ll safe;
    while(leftPos-1 <= rightPos ){
        if(L == R ){
            safe = counter;
            R += V[rightPos];
            L += V[leftPos];
            rightPos--;
            leftPos++;
            counter = counter + 2;
            continue;
        }
        else if(L < R){
            L = L + V[leftPos];
            leftPos++;
            counter++;
            continue;

        }
        else if (R < L){
            R = R + V[rightPos];
            rightPos--;
            counter++;
            continue;
        }
        else { 
            break; 
        } 
    }
    cout << safe << "\n";
    return 0;
}