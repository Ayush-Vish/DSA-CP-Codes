#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
/**
 * vector<int> pre(n-1);
      for(int i=0 ;i <n -1  ;i ++) {
            if(a[i] < a[i+1] || a[i] < b[i+1] || b[i] < b[i+1] || b[i] < a[i+1]) {
                  pre[i] =1;
            }
      }
      for(auto it : pre){
            cout <<  it << " ";
      }
      cout << endl;
      int ans =0;
      for(int i=0,  j=0; i < n-1 ;i ++) {
            if(pre[i] ==1 )  {

                  j = i ;
                  while(a[i] ==1) {
                        i ++;
                  }
                  int len = i-j +1 ;
                  debug(len);
                  ans += (n*(n+1)/2);
            }
      }
      cout << ans << endl;
 */
/**
 * Observations:
 * 
 * Soo, we have give tow array a and b we need to find the no of subarrays such that
 *  c[i] = a[i] | b[i]  <  c[i+1] = a[i+1] | b[i+1]
 * we actually need to find the subaary 
 *    just use a sliding Window  
 * We cannot actaully use Sliding Window because the earlier decision affects the upcoming decisions. 
 * not able to solve during contest Need to upsolve.
 * 
 * so let dp[i] -> denotes 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >>n ;
      vector<int>a(n),b(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }
      for(int i=0 ;i < n ;i ++) {cin >> b[i];}
      
    
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
