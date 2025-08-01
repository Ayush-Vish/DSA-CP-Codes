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
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }
int gcd(int a, int b) { if(b==0) return a; return gcd(b, a%b); }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }
int modInverse(int a) { return fastPow(a, mod-2); }
int modAdd(int a, int b) { return (a + b) % mod; }
int modSub(int a, int b) { return (a - b + mod) % mod; }

int _,dis1=1,dis2= 1 , node1,node2 ;
vector<int> __,dist;
vector<vector<int>> __2d,adj;

void dfs_(int src , int depth , int parent ) {
      if(depth > dis1) {
            dis1 = depth;
            node1 = src;
      }
      for(auto it : adj[src]) {
            if(it != parent) {
                  dfs_(it,depth +1 , src);
            }
      }
}
void dfs__(int src , int depth , int parent ) {
      if(depth > dis2) {
            dis2 = depth;
            node2 = src;
      }
      dist[src] = depth;
      // cout << src+1  << " " << depth << endl;
      for(auto it : adj[src]) {
            if(it != parent) {
                  dfs__(it,depth +1 , src);
            }
      }
}

void dfs2(int src, int parent,int depth  ) {

      dist[src] = max(dist[src],depth);
      for(auto it : adj[src] ) {
            if(it != parent) {
                  dfs2(it,src,depth +1 );
            }
      }
}
void dfs1(int src, int parent,int depth  ) {

      dist[src] = max(dist[src],depth);
      for(auto it : adj[src] ) {
            if(it != parent) {
                  dfs1(it,src,depth +1 );
            }
      }
}



void solve(){
      int n ;
      cin >> n ;
      dist.resize(n,0);
      adj.resize(n);
      for(int i=1 ;i < n ;i ++  ) {
            int a , b ;
            cin >>a >> b ;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      dfs_(0,1,-1);
      dfs__(node1,1,-1);


      dfs1(node1,-1,1);

      dfs2(node2,-1,1);

      for(auto it : dist )
            cout << it -1  << " ";


     
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
//     cin >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
