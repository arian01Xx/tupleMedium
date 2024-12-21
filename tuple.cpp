#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define ll long long
vector<ll> xm{+1,-1,0,0};
vector<ll> ym{0,0,+1,-1};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<tuple<ll, ll, ll, ll>> pq; //distancia, x, y, incremento/decremento

        ll n=moveTime.size();
        ll m=moveTime[0].size();
        vector<ll> t(m, 1e15); //tiempo minimo
        vector<vector<ll>> dist(n, t);
        pq.push({0,0,0,0});
        dist[0][0]=0;

        ll ans, ex, nx; //respuesta final, incremento y proximo incremento

        while(!pq.empty()){
            ll d=-get<0>(pq.top());
            ll x=get<1>(pq.top());
            ll y=get<2>(pq.top());
            ll dec=get<3>(pq.top()); //indicador incremento/decremento actual
            pq.pop();
            if(dec==0){
                nx=1;
                ex=1;
            }else{ //si es diferente a cero
                nx=0;
                ex=2;
            }
            if(dist[x][y]<d) continue;
            if(x==n-1 && y==m-1){ //si llegaron al final
                ans=d; //se iguala a la distancia
                break; //rompe el codigo para siempre
            }
            for(int i=0; i<4; ++i){ //revisa a partir de las 4 direcciones, arriba, abajo, izquierda y derecha
                ll xn=x+xm[i];
                ll yn=y+ym[i];
                if(xn >=0 && xn<n && yn>=0 && yn<m){ //se asegura de establecer los limites
                    ll a=moveTime[xn][yn];
                    ll now=max(d+ex, a+ex); //lo actualiza al mayor
                    if(dist[xn][yn]> now){
                        dist[xn][yn]=now;
                        pq.push({-now, xn, yn, nx});
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}