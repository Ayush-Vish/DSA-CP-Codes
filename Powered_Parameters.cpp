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
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }

        return hash1;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    takeInput(arr, n);
    int ans =0 ;
    unordered_map<pair<int,int> , int , hash_pair  > mpp ;

    for (int i=0 ;i < n ;i ++ ) {
        int num1 = arr[i] ;
        if(arr[i] == 1 ) {
            ans += n ;
            continue;
        }else  {
            for (int j =0 ; j <=n && j <=30   ;j ++ ) {
              
                ans  ++ ;

            }
        }
    }
    cout << ans  << endl ;  
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