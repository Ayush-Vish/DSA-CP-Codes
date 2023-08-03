class Solution {
public:
    void solve(int idx , vector<int>& arr , set<vector<int>>  &ans  , vector<int> ds  ) {
        if(idx >= arr.size()) {
            ans.insert(ds);
            return ;
        }
        solve(idx +1  , arr , ans , ds) ;
        ds.push_back(arr[idx]);
        
        solve(idx + 1 , arr , ans , ds) ;
        ds.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ans; 
        sort(nums.begin() , nums.end()) ;
        vector<int> ds;
        solve(0 , nums , ans , ds );
        vector<vector<int >> matrix;
        for(auto it : ans) {
            matrix.push_back(it);
        }
        return matrix;
    }
};