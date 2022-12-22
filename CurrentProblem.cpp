#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define mod(x, m) (((x % m) + m) % m)
#define mxn 100005
#define mxm 105
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<int, pii> pip;
 
int n, k, l, esq, dir;
ll v1[mxn], v2[mxn], resp, atual1, atual2;
set<pii> titu, res;

int main(){
    fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v1[i];
    }
    for(int i=1; i<=n; i++){
        cin >> v2[i];
    }
    cin >> k >> l;

    for(int i=1; i<=k; i++){
        atual1+=v1[i];
        atual2+=v2[i];
        titu.insert({v2[i], i});
    }
    while(sz(titu)>l){
        res.insert(*titu.begin());
        atual2-=((*titu.begin()).f);
        titu.erase(titu.begin());
    }
    resp=max(resp, atual1+atual2);

    esq=k, dir=n+1;
    int cont=k, can=0;

    while(cont--){
        atual1-=v1[esq];

        auto it1 = titu.find({v2[esq], esq});
        auto it2 = res.find({v2[esq], esq});

        if(it1!=titu.end()){
            atual2-=(*it1).f;
            titu.erase(it1);
            can=1;
        }else if(it2!=res.end()){
            res.erase(it2);
            can=0;
        }

        esq--;
        dir--;

        atual1+=v1[dir];
        res.insert({v2[dir], dir});

        if(can){
            auto it3 = res.end();
            it3--;
            titu.insert(*it3);
            atual2+=(*it3).f;
            res.erase(it3);
        }else{
            auto it4 = titu.begin();
            auto it5 = res.end();
            it5--;

            if((*it4).f<(*it5).f){
                res.erase(it5);
                res.insert(*it4);

                atual2-=(*it4).f;
                titu.erase(it4);

                titu.insert(*it5);
                atual2+=(*it5).f;
            }
        }

        resp=max(resp, atual1+atual2);
    }
    cout << resp << endl;
    return 0;
}
