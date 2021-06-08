#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 15
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
typedef pair<int, int> pii;
typedef pair<pii, pii> pip;

void file(string name){
    fastio;
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n, cor[mxn][mxn][mxn], resp[mxn];
pip coord[mxn];
char ma[mxn][mxn];

int main(){
    file("art");
    //fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> ma[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ma[i][j]=ma[i][j]-'0';
            resp[ma[i][j]]=1;
        }
    }
    for(int k=1; k<=9; k++){
        coord[k].f.f=INF;
        coord[k].f.s=INF;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(ma[i][j]==k){
                    coord[k].f.f=min(coord[k].f.f, i);
                    coord[k].f.s=min(coord[k].f.s, j);
                    coord[k].s.f=max(coord[k].s.f, i);
                    coord[k].s.s=max(coord[k].s.s, j);
                } 
            }
        }
    }
    for(int k=1; k<=9; k++){
        for(int i=coord[k].f.f; i<=coord[k].s.f; i++){
            for(int j=coord[k].f.s; j<=coord[k].s.s; j++){
                cor[k][i][j]=1;
            }
        }
    }
    for(int k=1; k<=9; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(cor[k][i][j] && ma[i][j]!=k){
                    resp[ma[i][j]]=0;
                } 
            }
        }
    }
    int ans=0;
    for(int i=1; i<=9; i++){
        ans+=resp[i];
    }
    cout << ans;
    return 0;
}
