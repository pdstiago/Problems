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

int n, m;
vector<string> spo, pla;

int main(){
    //fastio;
    file("cownomics");
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string agr;
        cin >> agr;
        spo.pb(agr);
    }
    for(int i=0; i<n; i++){
        string agr;
        cin >> agr;
        pla.pb(agr);
    }
    int resp=0;
    for(int i=0; i<m; i++){
        set<char> let1, let2;
        for(int j=0; j<n; j++){
            let1.insert(spo[j][i]);
        }
        for(int j=0; j<n; j++){
            let2.insert(pla[j][i]);
        }
        int can=1;
        for(char i:let1){
            if(let2.count(i)){
                can=0;
            }
        }
        for(char i:let2){
            if(let1.count(i)){
                can=0;
            }
        }
        if(can){
            resp++;
        }
    }
    cout << resp << endl;
    return 0;
}
