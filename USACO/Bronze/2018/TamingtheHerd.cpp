#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 105
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

int n, v[mxn], respmin, respmax;

int main(){
    file("taming");
    //fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    if(v[1]>0){
        cout << -1;
        return 0;
    }
    v[1]=0;
    for(int i=n; i>=1; i--){
        if(i<n && v[i]>=0 && v[i+1]>0 && v[i]!=v[i+1]-1){
            cout << -1;
            return 0;
        }
        if(v[i]>=i){
            cout << -1;
            return 0;
        }
        if(v[i]>0 && v[i-v[i]]>0){
            cout << -1;
            return 0;
        }
        if(v[i]>0){
            v[i-v[i]]=0;
        }
        if(i<n && v[i]==-1 && v[i+1]>0){
            v[i]=v[i+1]-1;
        }else if(v[i]==-1){
            respmax++;
        }
        if(!v[i]){
            respmin++;
            respmax++;
        }
    }
    cout << respmin << es << respmax;
    return 0;
}
