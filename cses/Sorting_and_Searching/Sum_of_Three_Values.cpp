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

void solve(){
      int n , t  ;
      cin >> n >> t ;
      vector<pair<int,int>> a(n );
      for(int i=0 ;i  < n ;i ++ ) {
            cin >> a[i].first;
            a[i].second = i + 1;
      }
      sort(a.begin() , a.end());    
      for(int i=0 ;i <n ;i ++ )  {
            int tar = t - a[i].first;
            int j = i +1 ;
            int k = n-1 ;
            while(j < k ){
                  if(a[j ].first + a[k ].first> tar) {
                        k -- ;
                  }else if (a[j ].first + a[k ].first < tar ) {
                        j ++ ;
                  }else {
                        cout << a[i].second  << " " << a[j].second << " "  << a[k].second << endl;
                        return ;

                  }
            } 

      }
      cout << "IMPOSSIBLE" <<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
//     cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
