#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000009
#define mod 100005
#define mxn 200005
#define mxm 1005
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
typedef pair<int, pii> pip;

int n, m, k, p, cont, parei;
ll atual=1;
string senha, got="", res="";
vector<char> prob[28];

int main(){
    cin >> n >> m >> k >> senha;
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            char a;
            cin >> a;
            prob[i].pb(a);
        }
    }
    cin >> p;
    p--;
    for(int i=m-1; i>=0; i--){
        atual*=k;
        got+=prob[i][p%k];
        p-=(atual-1);
        if(p<=0){
            parei=i;
            break;
        }
    }
    cout << got << endl;
    for(int i=parei-1; i>=0; i--){
        got+=prob[i][0];
    }
    for(int i=n-1; i>=0; i--){
        if(senha[i]=='#'){
            res+=got[cont++];
        }else{
            res+=senha[i];
        }
    }
    for(int i=n-1; i>=0; i--){
        cout << res[i];
    }
    return 0;
}
