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

int n, k, resp=-1, v[1005];

int main(){
    //fastio;
    file("diamond");
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        int cont=1;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(v[i]<=v[j] && v[j]-v[i]<=k){
                cont++;
            }
        }
        resp=max(resp, cont);
    }
    cout << resp << endl;
    return 0;
}
