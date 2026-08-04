class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        int start = 0;
        int end = n-1;
        while( start < end){
            int wl = end-start;
            int wh = min(heights[start],heights[end]);
            maxi = max(maxi,wl*wh);
            if(heights[start] < heights[end]){
                start ++;
            }
            else{
                end--;
            }
        }
        return maxi;
    }
};
