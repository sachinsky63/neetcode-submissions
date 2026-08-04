class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        //multimap -> sorted automatically by key
        multimap<int,int,greater<int>> sort_f;
        for(auto it : mp){
            sort_f.insert({it.second,it.first});
        }
        int count =0;
        for(auto & i : sort_f){
            ans.push_back(i.second);
            count++;
            if(count == k){
                break;
            }
        }
        return ans;

    }
};
