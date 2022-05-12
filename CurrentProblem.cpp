#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define mxn 100005
#define mxm 505
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

int m[5][5], soma, qntl[5][2], qntc[5][2], qntd[2][2]; 

int main(){
    fastio;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin >> m[i][j];
        }
    }
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(m[i][j]){
                qntl[i][1]++;
            }
            qntl[i][0]+=m[i][j];
        }
    }
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(m[j][i]){
                qntc[i][1]++;
            }
            qntc[i][0]+=m[j][i];
        }
    }
    for(int i=1; i<=3; i++){
        if(m[i][i]){
            qntd[0][1]++;
        }
        qntd[0][0]+=m[i][i];
    }
    int j=0;
    for(int i=3; i>=1; i--){
        j++;
        if(m[j][i]){
            qntd[1][1]++;
        }
        qntd[1][0]+=m[j][i];
    }
    for(int i=1; i<=3; i++){
        if(qntl[i][1]==3){
            soma=qntl[i][0];
        }
    }
    for(int i=1; i<=3; i++){
        if(qntc[i][1]==3){
            soma=qntc[i][0];
        }
    }
    for(int i=0; i<2; i++){
        if(qntd[i][1]==3){
            soma=qntd[i][0];
        }
    }
    for(int i=1; i<=3; i++){
        if(qntl[i][1]==2){
            for(int j=1; j<=3; j++){
                if(!m[i][j]){
                    m[i][j]=soma-qntl[i][0];
                }
            }
            qntl[i][1]++;
            qntl[i][0]=soma;
        }
    }
    cout << realsoma << endl;
    return 0;
}
