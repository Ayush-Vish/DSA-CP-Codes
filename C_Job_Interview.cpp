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
int f(int i, int n,int m , vector<int>&prog ,vector<int>&test , int sum ) { 
      if(n ==0 && m ==0 ) {
            cout <<sum <<endl;
            return 0;
      }
      if(i==0 ) {
            if(prog[i]>test[i]) {
            if(n>0) {
                  return   prog[i] ;
            }else if( m>0) {
                  return  test[i];
            }
      }else {
            if(m>0) {
                  return  test[i] ;
            }else if(n>0) {
                  return  prog[i] ;
            }
      }
      }

      int take  = -1e9;
      if(prog[i]>test[i]) {
            if(n>0) {
                  take = prog[i] + f(i-1,n-1,m,prog,test ,sum + prog[i]) ;
            }else if( m>0) {
                  take = test[i] + f(i-1,n,m-1,prog,test,sum + test[i]);
            }
      }else {
            if(m>0) {
                  take = test[i] +f(i-1,  n,m-1,prog,test,sum + test[i]  );
            }else if(n>0) {
                  take = prog[i] +f(i-1, n-1 , m , prog , test,sum + prog[i]  ) ;
            }
      }

      int not_take = f(i-1, n,m,prog,test,sum);
      return max(take , not_take);

}
void solve()
{
      int n ,m ;
      cin >> n >> m;
      vector<int> prog(n+m+1);
      vector<int> test(n+m+1);
      takeInput(prog,n+m+1);
      takeInput(test,n+m+1);
      cout <<f(n+m,n,m,prog,test, 0 )<<endl;
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