class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int>st;
        st.push(0);
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            while(!st.empty()){
                int top = st.top();
                if(t[top] < t[i]){
                    ans[top]=(i-top);
                    st.pop();
                }
                else break;
            }
            st.push(i);
        }
       return ans;  
    }
};