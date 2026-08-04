class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int bottom = n-1;
        int top = 0;
        while( top <= bottom ){
            int mid = (top + (bottom - top)/2);
            if(target > matrix[mid][m-1]){
                top = mid+1;
            }
            else if(target < matrix[mid][0]){
                bottom = mid-1;
            }
            else{
                break;
            }
        }
        if(!(top <= bottom)){
            return false;
        }
        int row = (top + (bottom - top)/2);
        int l = 0;
        int r = m-1;
        while ( l <= r){
            int mid = (l + (r-l)/2);
            if(target > matrix[row][mid]){
                l = mid + 1;
            }
            else if ( target < matrix[row][mid]){
                r = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
