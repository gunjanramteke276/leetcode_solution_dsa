class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0;
        int e = arr.size() - 1;

        while (s < e) {
            
            int mid = s + (e - s) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Going UP → peak is on RIGHT
                s = mid + 1;
            }
            else {
                // Going DOWN → peak is at mid or LEFT
                e = mid;
            }
        }

        return s;
    }
};