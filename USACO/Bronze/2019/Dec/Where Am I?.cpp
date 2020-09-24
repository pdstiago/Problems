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
    file("whereami");
    int n, resp=INF;
    map<string, int> mapa;
    cin >> n;
    string atual;
    cin >> atual;
    for(int i=0; i<sz(atual); i++){
        string att="";
        att+=atual[i];
        mapa[att]++;
        for(int j=i+1; j<sz(atual); j++){
            att+=atual[j];
            mapa[att]++;
        }
    }
    set<int> sla;
    for(pair<string, int> i:mapa){
        if(i.s>1){
            sla.insert(sz(i.f));
        }
    }
    for(pair<string, int> i:mapa){
        if(!(sla.count(sz(i.f)))){
            resp=min(resp, sz(i.f));
        }
    }
    cout << resp << endl;
    return 0;
}
