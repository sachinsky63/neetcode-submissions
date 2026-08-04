class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        int l =0;
        int r = 0;
        while( r < n){
            // pop smaller value
            while(!dq.empty() && nums[r] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(r);

            // remove left value from the window
            if( l > dq.front()){
                dq.pop_front();
            }

            if(r+1 >= k){
                ans.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
