class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>pr;
        stack<double>st;
        int n = position.size();
        for(int i=0; i<n; i++){
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());
        for(auto it : pr){
            int pos = it.first;
            double speed = it.second;
            double time = (double)(target - pos)/speed;
            st.push(time);
            if(st.size() >= 2 ){
                double curr = st.top();
                st.pop();
                double prev = st.top();
                if(curr <= prev){
                    // merge
                }
                else{
                    st.push(curr);
                }
            } 
        }
        return st.size();
    }
};
