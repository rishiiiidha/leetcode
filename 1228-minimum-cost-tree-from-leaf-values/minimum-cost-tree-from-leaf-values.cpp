class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        stack<int>st;
        int n = arr.size();
        int res = 0;
        st.push(INT_MAX);
        for(int i=0;i<n;i++){
            int num = arr[i];
            while(st.top() <= num){
                int mid = st.top();
                st.pop();
                res += mid*(min(num,(int)st.top()));
            }
            st.push(num);
        }
        while((int)st.size() > 2){
            int top = st.top();
            st.pop();
            res+=top*((int)st.top());
        }
        return res;
    }

};


