#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';

#define int long long int
void solve(){
      string s ;
      cin >> s ;
      int z =0 ,o=0, ans1 =0 , ans2 = 0 ;
      int prev =0;

      if(s[0] == '1') prev =1 ;
      else prev = 0;


      int cnt= 1;
      int n =s.size();
      for(int i=1 ;i < n ;i ++) {
            if(s[i] == prev) {
                  cnt ++;
            }else {
                  if(cnt >1) {
                        ans1 += cnt -1;
                        ans2 += 

                  } 
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
