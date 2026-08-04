class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            int a = nums[i];
            if(i >0 && a == nums[i-1]){
                continue;
            }
            // two pointer
            int left = i+1;
            int right = n-1;
            while( left < right){
                if(a + nums[left] + nums[right] > 0){
                    right--;
                }
                else if(a + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    ans.push_back({a,nums[left],nums[right]});
                    left++;

                    // check the left pointer if the same 
                    while(nums[left] == nums[left-1] && left < right){
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
