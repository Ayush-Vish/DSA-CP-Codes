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
      takeInput(a,n);
      int mini = INT_MAX, mini2 = INT_MAX, minIndex = -1, mini2Index = -1;
      for (int i = 0; i < n; i++) {
            if (a[i] < mini) {
                  mini2 = mini;
                  mini2Index = minIndex;
                  mini = a[i];
                  minIndex = i;
            } else if (a[i] < mini2) {
                  mini2 = a[i];
                  mini2Index = i;
            }
      }
      int diff = abs(mini-mini2),diff1= abs(minIndex -mini2Index);
      if(diff1 <= diff ) {
            cout << "YES" << endl;
      }else{
            cout << "NO" << endl;
      }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}