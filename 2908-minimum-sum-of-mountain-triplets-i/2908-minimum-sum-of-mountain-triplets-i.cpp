class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MAX;

        for (int j = 1; j < n - 1; j++) {

            int left = INT_MAX;
            int right = INT_MAX;

            // Find smallest on left
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    left = min(left, nums[i]);
                }
            }

            // Find smallest on right
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j]) {
                    right = min(right, nums[k]);
                }
            }

            if (left != INT_MAX && right != INT_MAX) {
                ans = min(ans, left + nums[j] + right);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};