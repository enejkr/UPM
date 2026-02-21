#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
int getCount(string S);
int main (){
    int T; 
    cin >> T; 
    for(int i = 0; i < T; i++){
        string S; 
        int N; 
        cin >> N;
        cin >> S;
        int max = 0;
         for (int j = 0; j < N; j++){
            int count = getCount(S);
            if(max < count) 
                max = count;
            string nS = S.substr(N-1,N) + S.substr(0,N-1);
            S = nS;
        }
        cout << max << "\n";
    }
   

    return 0;
}
int getCount(string S){
    int counter = 1;
    char curChar = S[0];
    for (int i = 0; i < (int) S.size(); i++){
        if(curChar == S[i]){
            continue;
        }
        else{
            curChar = S[i];
            counter++;
        }
    }
    //cout << "counter for S: " << S << " = " << counter << "\n";
    return counter;
}