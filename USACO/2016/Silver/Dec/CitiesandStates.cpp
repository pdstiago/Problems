#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 100005
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
typedef pair<int, int> pii;
typedef pair<ll, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
    //fastio;
    file("citystate");
    int n, resp=0;
    map<pair<string, string>, int> mapa;
    cin >> n;
    for(int i=0; i<n; i++){
        string name, sc, rn="";
        cin >> name >> sc;
        rn+=name[0];
        rn+=name[1];
        if(sc!=rn){
            resp+=mapa[{sc, rn}];
            mapa[{rn, sc}]++;
        }
    }
    cout << resp << endl;
    return 0;
}
