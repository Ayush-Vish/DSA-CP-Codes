#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> seive(int n) {
    vector<int> prime(n+1, 1);
    for(int i=2; i*i<=n; i++)
        if(prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j]=0;
    return prime;
}

template <typename T>
void takeInput(vector<T> &a, int n) {
    for(int i=0; i<n; i++) {
        T ele; cin >> ele; a[i] = ele;
    }
}

template <typename T>
void printArr(vector<T> &a) {
    for(auto it : a) cout << it << " ";
    cout << endl;
}

int fastPow(int a, int b) {
    int res=1;
    while(b) {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod; b>>=1;
    }
    return res;
}
int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }
int modInverse(int a) { return fastPow(a, mod-2); }
int modAdd(int a, int b) { return (a + b) % mod; }
int modSub(int a, int b) { return (a - b + mod) % mod; }
int _,n,q,logk = 21 ;
vector<int> __,level;
vector<vector<int>> __2d,dp,adj;

void dfs(int src,int parent ) {
      level[src] = level[parent] +1 ;
      dp[src][0] = parent;
      for(auto it : adj[src]) {
            if(it != parent) {
                  dfs(it,src);
            }
      }
}

int lca (int a, int b ) {
      if(level[b ] > level[a]){
            swap(a,b);
      }
      int diff = level[a] - level[b];
      for(int i=logk-1 ;i >=0; i -- ) {
            if((1LL << i ) & diff) {
                  a = dp[a][i];
            }
      }
      if(a == b ) {
            return a ;

      }
      for(int i=logk-1 ;i>=0 ; i -- ) {
            if(dp[a][i] != dp[b][i]){
                  a = dp[a][i];
                  b = dp[b][i];
            }
      }
      return dp[a][0];
}

void solve(){
      cin >> n >> q ;
      adj.resize(n+1);
     
      dp.resize(n +1,vector<int>(logk));
      level.resize(n +1 );
      for(int i=1 ;i < n ;i ++) {
            int a,b; 
            cin >>a >>b ;
             adj[a].push_back(b);
            adj[b].push_back(a);
            
            // dp[b][0] = a;
      }
      level[0] = -1; 
      dfs(1,0);
      for(int j=1 ; j<logk; j ++ ) {
            for(int i=1 ;i <=n ;i ++ ) {
                  dp[i][j] = dp[dp[i][j-1]][j-1];
            }
      }
 
      // for(auto it : level)
      //       cerr << it << " ";
      for(int z =0 ;z < q ;z ++ ) {
            int a,b; 
            cin >>a >> b ;
            cout << level[a] + level[b] - 2*level[lca(a,b)] <<endl;

      }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // === FILE REDIRECTION ===
    freopen("input.txt", "r", stdin);    // read from "input.txt"
    freopen("output.txt", "w", stdout);  // write to "output.txt"

    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";

    return 0;
}
