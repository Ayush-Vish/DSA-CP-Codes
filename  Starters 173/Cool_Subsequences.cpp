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
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
void solve(){
      int n ;
      cin >> n ;
      vector<int>a(n);
      map<int,int> mpp;

      for(int i=0 ; i <n ;i ++ ) {
            cin >> a[i];
            mpp[a[i]] ++ ;

      }
      int ans = -1 ;

      for(auto it : mpp ) {
            if(it.second  >1) {
                  ans = it.first;
                  break;
            }
      }
      if(ans == -1 ) {
            cout << ans << endl;

      }else {
            cout << 1 << endl;
            cout << ans << endl;

      }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1 ;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}