class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int i=0;
        int j =0;
        int n = s.size();
        int maxi =0;
        while(j < n){
            while(count[s[j]] !=0){
                count[s[i]] =0;
                i++;
            }
            count[s[j]] =1;
            j++;

            maxi = max(maxi, j-i);
        }
        return maxi;
    }
};
