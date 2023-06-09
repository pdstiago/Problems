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
typedef pair<int, int> pii;
typedef pair<ll, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n, t, infec[105], kc[105], pz, zero[105], ks[252];
string att;
pip v[255];

bool test(int pz, int k){
    memset(infec, 0, sizeof(infec));
    memset(kc, 0, sizeof(kc));
    infec[pz]=1;
    for(int i=0; i<t; i++){
        int pri=v[i].s.f;
        int seg=v[i].s.s;
        if(infec[pri]){
            kc[pri]++;
        }
        if(infec[seg]){
            kc[seg]++;
        }
        if(kc[pri]<=k && infec[pri]){
            infec[seg]=1;
        }
        if(kc[seg]<=k && infec[seg]){
            infec[pri]=1;
        }
    }
    for(int i=1; i<=n; i++){
        if(infec[i]!=(att[i-1]-'0')){
            return false;
        }
    }
    return true;
}

int main(){
    //fastio;
    file("tracing");
    cin >> n >> t >> att;
    for(int i=0; i<t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[i].f=a;
        v[i].s={b, c};
    }
    sort(v, v+t);
    for(int i=1; i<=n; i++){
        for(int j=0; j<=t+1; j++){
            if(test(i, j)){
                zero[i]=1;
                ks[j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(zero[i]){
            pz++;
        }
    }
    cout << pz << es;
    int upper=0, lower=0;
    for(int i=t+1; i>=0; i--){
        if(ks[i]){
            upper=i;
            break;
        }
    }
    for(int i=0; i<=t+1; i++){
        if(ks[i]){
            lower=i;
            break;
        }
    }
    cout << lower << es;
    if(upper==t+1){
        cout << "Infinity";
    }else{
        cout << upper;
    }
    return 0;
}
