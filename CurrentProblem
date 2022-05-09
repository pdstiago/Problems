#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 200005
#define mxm 105
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
typedef pair<string, string> pii;
typedef pair<int, pii> pip;

int n, q;
ll v[mxn], l[mxn], r[mxn], maior=INFL, menor=-INFL;

int main(){
    fastio;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        maior=max(maior, v[i]);
        menor=min(menor, v[i]);
    }
    for(int i=1; i<=q; i++){
        int x;
        cin >> x;
        menor=min(menor, menor+x);
        maior=max(maior, maior+x);
    }
    return 0;
}

//https://neps.academy/br/exercise/1588
