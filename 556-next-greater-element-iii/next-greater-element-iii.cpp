class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int k = s.size() - 2;
        int i = k;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0)
            return -1;
        int j = k + 1;
        while (s[j] <= s[i]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};