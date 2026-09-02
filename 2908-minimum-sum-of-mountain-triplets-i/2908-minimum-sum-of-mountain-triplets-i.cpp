class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        // Smallest element on the left
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = min(left[i - 1], nums[i]);
        }

        // Smallest element on the right
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        int ans = INT_MAX;

        // j is the middle/highest element
        for (int j = 1; j < n - 1; j++) {

            if (left[j - 1] < nums[j] &&
                right[j + 1] < nums[j]) {

                ans = min(ans,
                          left[j - 1] + nums[j] + right[j + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};