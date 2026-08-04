class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while( start <= end){
            int mid = start + (end - start)/2;
            long long total =0;
            for(int i=0; i<n; i++){
                total += piles[i]/mid;
                if(piles[i] % mid){
                    total++;
                }
            }
            if(total > h){
                start = mid+1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};
