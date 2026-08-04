class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            int curr = numbers[l]+numbers[r];
            if(curr < target){
                l ++;
            }
            else if(curr > target){
                r--;
            }
            else{
                return {l+1,r+1};
                
            }
        }
    }
};
