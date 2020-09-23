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
    file("notlast");
    int n;
    map<string, int> mapa;
    cin >> n;
    mapa["Bessie"]=0;
    mapa["Elsie"]=0;
    mapa["Daisy"]=0;
    mapa["Gertie"]=0;
    mapa["Annabelle"]=0;
    mapa["Maggie"]=0;
    mapa["Henrietta"]=0;
    for(int i=0; i<n; i++){
        int a;
        string nome;
        cin >> nome >> a;
        mapa[nome]+=a;
    }
    set<pair<int, string> > sla;
    set<int> sla2;
    for(pair<string, int> i:mapa){
        sla.insert({i.s, i.f});
        sla2.insert(i.s);
    }
    int cont=0;
    string resp;
    if(sz(sla2)>1){
        set<int>::iterator it=sla2.begin();
        it++;
        int segm=*it;
        set<pair<int, string> >::iterator it2=sla.begin();
        for(it2; it2!=sla.end(); it2++){
            pair<int, string> agr=*it2;
            if(agr.f==segm){
                cont++;
                resp=agr.s;
            }
        }
        if(cont>1){
            cout << "Tie" << endl;
        }else{
            cout << resp << endl;
        }
    }else{
        cout << "Tie" << endl;
    }
    return 0;
}
