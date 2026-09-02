/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &a) {
        int s = 0, e = a.length() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (a.get(mid) < a.get(mid + 1))
                s = mid + 1;
            else
                e = mid;
        }

        return s;
    }

    int binarySearch(MountainArray &a, int target,
                     int s, int e, bool inc) {

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int x = a.get(mid);

            if (x == target)
                return mid;

            if (inc) {
                if (target > x)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            else {
                if (target > x)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &a) {

        int peak = findPeak(a);

        // Search left first for minimum index
        int ans = binarySearch(a, target, 0, peak, true);

        if (ans != -1)
            return ans;

        // Search right
        return binarySearch(a, target, peak + 1,
                            a.length() - 1, false);
    }
};