class Solution {
public:
    double findMedianSortedArrays(vector<int>& p, vector<int>& q) {
        int n = p.size();
        int m = q.size();
        int i=0;
        int j=0;
        vector<int>res;
        while(i<n && j<m){
            if(p[i]<=q[j]){
                res.push_back(p[i]);
                i++;
            }
            else{
                res.push_back(q[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(p[i]);
            i++;
        }
        while(j<m){
            res.push_back(q[j]);
            j++;
        }
        int sz = res.size();
        if(sz % 2 == 1){
            return (double)res[sz/2];
        }
        double a = res[sz/2-1];
        double b = res[sz/2];
        return ((a+b)/2.0);    
    }
};