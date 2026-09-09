class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        long long value = 1;
        
        for (int k = 0; k <= rowIndex; k++) {
            ans.push_back(value);
            value = value * (rowIndex - k) / (k + 1);
        }
        
        return ans;
    }
};