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

int n;
pii v[105];

int main(){
    //fastio;
    file("triangles");
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i].f >> v[i].s;
    }
    ll maior=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            for(int z=0; z<n; z++){
                if(z==j || z==i) continue;
                if(v[i].f==v[j].f && v[z].s==v[i].s){
                    ll h=v[j].s-v[i].s;
                    ll b=v[z].f-v[i].f;
                    ll area=abs(h)*abs(b);
                    maior=max(maior, area);
                }
            }
        }
    }
    cout << maior << endl;
    return 0;
}
