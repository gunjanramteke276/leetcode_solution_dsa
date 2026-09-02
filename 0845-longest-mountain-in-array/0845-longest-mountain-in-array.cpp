class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int up = 0;
        int down = 0;
        int ans = 0;

        for (int i = 1; i < n; i++) {
            
            if (down > 0 && arr[i - 1] < arr[i]) {
                up = 0;
                down = 0;
            }

            if (arr[i - 1] < arr[i]) {
                up++;
            }
            else if (arr[i - 1] > arr[i]) {
                if (up > 0) {
                    down++;
                }
            }
            else {
                up = 0;
                down = 0;
            }

            if (up > 0 && down > 0) {
                ans = max(ans, up + down + 1);
            }
        }

        return ans;
    }
};