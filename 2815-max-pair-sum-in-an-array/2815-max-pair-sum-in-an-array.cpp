class Solution {
public:
    int maxSum(vector<int>& nums) {

        int maxNum[10];

        for(int i = 0; i < 10; i++)
            maxNum[i] = -1;

        int ans = -1;

        for(int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            int largest = 0;

            while(num > 0) {
                int digit = num % 10;

                if(digit > largest)
                    largest = digit;

                num = num / 10;
            }

            if(maxNum[largest] != -1) {

                int sum = nums[i] + maxNum[largest];

                if(sum > ans)
                    ans = sum;
            }

            if(nums[i] > maxNum[largest])
                maxNum[largest] = nums[i];
        }

        return ans;
    }
};