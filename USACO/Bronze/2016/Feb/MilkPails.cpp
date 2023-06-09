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

int memo[2005];

int main(){
    //fastio;
    file("pails");
    int x, y, m, resp=-1;
    cin >> x >> y >> m;
    queue<int> fila;
    fila.push(x);
    fila.push(y);
    memo[x]=1;
    memo[y]=1;
    while(!fila.empty()){
        int pri=fila.front();
        fila.pop();
        resp=max(resp, pri);
        if(!memo[pri+x] && pri+x<=m){
            memo[pri+x]=1;
            fila.push(pri+x);
        }
        if(!memo[pri+y] && pri+y<=m){
            memo[pri+y]=1;
            fila.push(pri+y);
        }
    }
    cout << resp << endl;
    return 0;
}
