class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi = 0;
        for(int num : st){
            // smallest element 
            if(st.find(num-1) == st.end()){ // isse smallest not present
                int count = 1;
                int curr = num;

                while(st.find(curr + 1) != st.end()){
                    count++;
                    curr++;
                }
                maxi = max(count,maxi);
            }
        }
        return maxi;
    }
};
