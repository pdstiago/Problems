#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define mxn 100005
#define mxm 505
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
typedef pair<string, int> pii;
typedef pair<int, pii> pip;

int n, v[8], pont[15], seq, resp;

int main(){
    fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        seq=1, resp=0;
        set<pii> sla;
        cout << "Teste " << i << endl;
        for(int j=1; j<=5; j++){
            cin >> v[j];
            pont[v[j]]++;
        }
        sort(v+1, v+6);
        for(int j=2; j<=5; j++){
            if(v[j]!=v[j-1]){
                seq=0;
            }
        }
        if(seq){
            resp+=v[1]+200;
        }
        for(int j=1; j<=13; j++){
            sla.insert(pont[j]);
        }
        if(sla.find(4)!=sla.end()){
            resp+=
        }
    }
    return 0;
}
