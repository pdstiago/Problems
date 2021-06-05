#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 1000005
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
typedef pair<string, int> pii;
typedef pair<int, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int memo[mxn], resp;

void solve(int day, vector<int> v1, vector<int> v2, int atual){
    if(day==5){
        memo[atual]=1;
        return;
    }
    if(day&1){
        for(int i=0; i<sz(v1); i++){
            vector<int> realv1=v1, realv2=v2;
            int agr=v1[i];
            realv1.erase(realv1.begin()+i);
            realv2.pb(agr);
            solve(day+1, realv1, realv2, atual-agr);
        }
    }else{
        for(int i=0; i<sz(v2); i++){
            vector<int> realv1=v1, realv2=v2;
            int agr=v2[i];
            realv2.erase(realv2.begin()+i);
            realv1.pb(agr);
            solve(day+1, realv1, realv2, atual+agr);
        }
    }
}

int main(){
    file("backforth");
    //fastio;
    vector<int> b1, b2;
    for(int i=0; i<10; i++){
        int x;
        cin >> x;
        b1.pb(x);
    }
    for(int i=0; i<10; i++){
        int x;
        cin >> x;
        b2.pb(x);
    }
    solve(1, b1, b2, 1000);
    for(int i=800; i<=1200; i++){
        resp+=memo[i];
    }
    cout << resp;
    return 0;
}
