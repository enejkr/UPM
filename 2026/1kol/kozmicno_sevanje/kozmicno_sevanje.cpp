#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
//N x1 y1 x2 y2 
//x y r 
struct tocka
{
    // pozicije
    ll x;
    ll y; 
    ll r = 0;
    double cena;// cena tocke
    ll index;
    ll prev; // index na prev point
    bool obiskano = false;
};
 
int main(){
    ll N;
    tocka start;
    tocka end;
    cin >> N >> start.x >> start.y >> end.x >> end.y;
    start.cena = 0;
    start.prev = -1;
    start.index = 0;
    end.cena = INT_MAX;
    end.index = 1;
    vector<tocka> tocke;
    tocke.emplace_back(start);
    tocke.emplace_back(end);
    for(ll i = 0; i < N; i++) {
        tocka t;
        cin >> t.x >> t.y >> t.r;
        t.cena = INT_MAX ;
        t.index = 2+i;
        tocke.emplace_back(t);
    }
   
    //cout << "Start: " << "("<< start.x<< ","<< start.y <<")\n" ; 
    //cout << "end: " << "("<< end.x<< ","<<  end.y << ")\n";
    //cout << "tocke: \n ";
    for(auto el: tocke){
        //cout << "tocka: " << "("<< el.x<< "," << el.y <<")\n";
    }
 
    ll cur = 0;
    while(!tocke[1].obiskano){
 
        tocke[cur].obiskano = true;
 
        for(ll i = 0; i < (int) tocke.size(); i++){
            if(tocke[i].obiskano) continue;// nemoreš po ze optimalnih poteh
 
            double weight = (double) sqrt(pow((tocke[cur].x - tocke[i].x),2) + pow((tocke[cur].y - tocke[i].y),2)) - (double)tocke[i].r - (double)tocke[cur].r;
            if(weight < 0) weight = 0;
 
            //cout << "izračunana teža za index i: " << i << " teža: " << weight << "\n";
            //shranim nov najboljši index pa mu nastavim novo pot kak sem pršu do sem
            if(tocke[cur].cena + weight < tocke[i].cena){
                //cout << "za ta index najboljsa teža  old " <<  tocke[i].cena << ", new: " << tocke[cur].cena + weight << "index: " << i<<"\n";
                tocke[i].cena = tocke[cur].cena + weight;
                tocke[i].prev = cur; 
            }
        }
 
        ll index = -1;
        for(ll i = 0; i < (int)tocke.size(); i++){
            if(!tocke[i].obiskano){
                if(index == -1 || tocke[i].cena < tocke[index].cena){
                    index = i;
                }
            }
        }
 
        if(index == -1) break;
 
        cur = index; //nov najboljš index
    }
    printf("%.9f\n", tocke[1].cena);
   
    return 0;
}