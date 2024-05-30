#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
void takeInput(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        a[i] = ele;
    }
}
void printArr(vector<int> &a)
{
    cout << endl;
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}
void solve()
{
   int n ;
   cin >> n; 
   vector<int> a(n);
   vector<int>b(n+1);
   takeInput(a,n);
   takeInput(b,n+1);
    
   int maxi = *max_element(a.begin(),a.end());
    int mini = *min_element(a.begin(),a.end());
      int ans =0 ;
      bool lastGuy = false;
      int lastEle = b[n];
      
      if(lastEle>maxi) {
            ans += lastEle - maxi;
            lastGuy = true;
            ans ++ ;
      }
      if(lastEle<mini) {
            ans += mini - lastEle;
            lastGuy = true;
            ans ++ ;
      }
      for(int i=0 ;i<n  && lastGuy == false;i++ ) {
            if(a[i] == lastEle) {

                  ans ++ ;
                  lastGuy = true;
                  break;
            }
      }
     
      for(int i=0 ;i < n ;i ++ ) {
            int diff =  abs(a[i] - b[i]);
            if(lastGuy == false) {
                  if(lastEle>a[i] &&lastEle<b[i] ) {
                        ans ++ ;

                        lastGuy = true;
                  }
                  if(lastEle<a[i] &&lastEle>b[i] ) {
                        ans ++ ;
                        lastGuy = true;
                  }
            }
            ans += diff;
      }
      cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}