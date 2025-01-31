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

vector<vector<int>> dp;

int f( int curr , int prev , vector<vector<int>>&a ) {
    
    if(curr == a.size()) return 0;
    if(dp[curr][prev +1 ] != -1 ) return dp[curr][prev +1 ];
    int one =0;
    if(prev  == -1  || a[prev][1] < a[curr][0] ) {
        one = a[curr][2] + f(curr +1 , curr,a);
    }
    int two  =f ( curr +1  , prev ,a  );
    return dp[curr][prev+1] =  max(one  , two ) ;
}

void solve(){
    int n ;
    cin >> n ;
    vector<vector<int>> a (n,vector<int>(3));
    dp.resize(n+1,vector<int>(n+1 , -1 )) ;
    for(int i=0 ;i < n ; i ++ ) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(),a.end());

    cout << f (0,-1 , a );


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        solve();
    return 0;
}