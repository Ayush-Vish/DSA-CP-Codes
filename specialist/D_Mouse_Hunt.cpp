#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
int n ;
vector<int> c,parent,mini, vis ;
const int MAXX = 1e5 +1;
vector<int>adj[MAXX];

int f(int node) {
      if(node == parent[node]) {
            return node;

      }
      return parent[node] = f(parent[node]);
}

void solve(){
      cin >> n ;
      c.resize(n+1);
      parent.resize(n+1);
      mini.resize(n+1, INT_MAX);
      for(int i=1; i <=n ;i ++) {
            cin >> c[i];
      }
      for(int i=1;i <= n ;i ++) {
            parent[i] = i ;
      }
      for(int b=1; b <=n ;b ++) {
            int a;
            cin >>a ;

            int ua = f(a);
            int ub = f(b);
            if(ua != ub){
                  parent[ub] = ua;
                  mini[ua] = min({mini[ua],c[ua],c[ub]});
            }

      }












    
}
bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
