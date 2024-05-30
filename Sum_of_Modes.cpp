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
   int n;
   cin >> n;
   string s;
   cin >> s;
   int one=0;
    int zero=0;
    int ans =0 ;

   for(int i=0;i<n;i ++ ) {
      for(int j=i;j<n;j++) {
        if(s[j]=='1') {
            one++;
        } else {
            zero++;
        }
        if(one== zero) {
            ans+=2;
        }else {
            ans ++ ;
        }
      }
      one  =0; 
      zero =0;     
   }
   cout <<ans << endl;
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