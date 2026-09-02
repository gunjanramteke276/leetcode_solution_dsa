class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size();
        int i = 0;

        // Go UP
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak cannot be at start or end
        if (i == 0 || i == n - 1) {
            return false;
        }

        // Go DOWN
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // Must reach the end
        return i == n - 1;
    }
};