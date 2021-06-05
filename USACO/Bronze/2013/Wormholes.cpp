#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 15
#define mxm 55
#define f first
#define s second
#define pb push_back
#define es " "
#define endl '\n'
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n, nextp[mxn], worm[mxn], memo[mxn];
pii v[mxn];

int check_cycle(){
    for(int i=1; i<=n; i++){
        int pos=i;
        memset(memo, 0, sizeof(memo));
        for(int j=0; j<n; j++){
            memo[pos]=1;
            pos=worm[nextp[pos]];
            if(memo[pos] && pos>0){
                return 1;
            }
        }
    }
    return 0;
}

int solve(){
    int x, resp=0;
    for(int i=1; i<=n+1; i++){
        if(!worm[i]){
            x=i;
            break;
        }
    }
    if(x>n){
        if(check_cycle()){
            return 1;
        }else{
            return 0;
        }
    }
    for(int i=x+1; i<=n; i++){
        if(!worm[i]){
            worm[x]=i;
            worm[i]=x;
            resp+=solve();
            worm[x]=0;
            worm[i]=0;
        }
    }
    return resp;
}

int main(){
    file("wormhole");
    //fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> v[i].f >> v[i].s;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i].s==v[j].s && v[i].f<v[j].f){
                if(!nextp[i] || v[nextp[i]].f-v[i].f>v[j].f-v[i].f){
                    nextp[i]=j;
                }
            }
        }
    }
    cout << solve();
    return 0;
}
