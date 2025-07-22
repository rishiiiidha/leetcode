class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int maxSum = 0, currSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); ++end) {
            while (seen.find(nums[end]) != seen.end()) {
                currSum -= nums[start];
                seen.erase(nums[start]);
                start++;
            }
            currSum += nums[end];
            seen.insert(nums[end]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};