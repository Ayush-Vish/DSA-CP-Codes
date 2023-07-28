class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size() ;
        int m  = matrix[0].size();
        map< pair<int ,int >  ,bool >  mpp;
        for(int i =0 ; i < n ; i++ ) {
            for(int j =0 ; j < m ;j++) {
                if(matrix[i][j] == 0) {
                    for(int k  =  0; k < matrix.size() ;k++) {
                        if(matrix[k][j] != 0 ) mpp[make_pair(k,j)] = true;
                    }
                    for(int k  =  0; k < matrix[i].size() ;k++) {
                        if(matrix[i][k] != 0 ) mpp[make_pair(i,k)] = true;
                    }
                }
                
            }
        }
        for(int i =0 ;i  < n ;i ++  ) {
            for(int j =0 ;j  < m ;j++ ) {
                if(mpp[{i,j}] == 1  ) {
                    matrix[i][j]  = 0 ;
                }
            }
        }
    }
};