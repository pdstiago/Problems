#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define f first
#define s second
#define pb push_back
#define es " "
#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mxn 100005
typedef pair<ll, ll> pii;
typedef pair<ll, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

ll n, best;
pii v[105];

int main(){
    fastio;
    file("lifeguards");
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i].f >> v[i].s;
    }
    sort(v, v+n);
    for(int i=0; i<n; i++){
        ll soma=0, last=-1;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(v[j].f>last){
                soma+=(v[j].s-v[j].f);
                last=v[j].s;
            }else{
                if(last<v[j].s){
                    soma+=abs(v[j].s-last);
                    last=v[j].s;
                }
            }
        }
        best=max(best, soma);
    }
    cout << best << endl;
    return 0;
}
