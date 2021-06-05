#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mxn 1005
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

int n;
string cows[8]={"Beatrice", "Bella", "Buttercup", "Bessie", "Belinda", "Blue", "Betsy", "Sue"}, cow[8]={"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
vector<string> need[10], resp;
map<string, int> ma;

int main(){
    file("lineup");
    //fastio;
    sort(cows, cows+8);
    sort(cow, cow+8);
    for(int i=0; i<8; i++){
        ma[cows[i]]=i;
    }
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string a, cow1="", cow2="";
        getline(cin, a);
        for(char j:a){
            if(j==' '){
                break;
            }
            cow1+=j;
        }
        reverse(all(a));
        for(char j:a){
            if(j==' '){
                break;
            }
            cow2+=j;
        }
        reverse(all(cow2));
        need[ma[cow1]].pb(cow2);
        need[ma[cow2]].pb(cow1);
    }
    do{
        int can=1;
        for(int i=0; i<8; i++){
            int vaca=ma[cow[i]];
            if(sz(need[vaca])==1){
                if(i>0 && i<=6){
                    if(cow[i-1]!=need[vaca][0] && cow[i+1]!=need[vaca][0]){
                        can=0;
                        break;
                    }
                }else if(i<=6){
                    if(cow[i+1]!=need[vaca][0]){
                        can=0;
                        break;
                    }
                }else if(i>0){
                    if(cow[i-1]!=need[vaca][0]){
                        can=0;
                        break;
                    }
                }
            }else if(sz(need[vaca])==2){
                if(i>0 && i<=6){
                    if(cow[i-1]==need[vaca][0] && cow[i+1]==need[vaca][1]){
                        
                    }else if(cow[i-1]==need[vaca][1] && cow[i+1]==need[vaca][0]){

                    }else{
                        can=0;
                        break;
                    }
                }else{
                    can=0;
                    break;
                }
            }
        }
        if(can){
            for(string i:cow){
                resp.pb(i);
            }
            break;
        }
    }while(next_permutation(cow, cow+8));
    for(string i:resp){
        cout << i << endl;
    }
    return 0;
}
