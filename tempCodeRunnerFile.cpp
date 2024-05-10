
   int n , x ;
   vector<int> arr(n);
    takeInput(arr,n);
    int dis1= 2*(x-arr[n-1]);
    int ans = INT_MAX;
    ans=min(ans , dis1);
    for(int i =n-1 ;i>=1 ;i--) {
        ans = min(arr[i] -arr[i-1] , ans ) ;
    }
    cout << min(arr[0],ans) <<endl;
}