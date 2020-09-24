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

int n, k, v[25], cont[25][25];

int main(){
    //fastio;
    file("gymnastics");
    cin >> k >> n;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> v[j];
        }
        for(int j=0; j<n; j++){
            for(int z=j+1; z<n; z++){
                cont[v[j]][v[z]]++;
            }
        }
    }
    int resp=0;
    for(int i=1; i<=20; i++){
        for(int j=1; j<=20; j++){
            if(cont[i][j]==k){
                resp++;
            }
        }
    }
    cout << resp << endl;
    return 0;
}
