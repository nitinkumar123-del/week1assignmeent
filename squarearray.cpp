class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        vector<int> res;

        // Separate negative and non-negative numbers
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                neg.push_back(nums[i] * nums[i]);
            else
                pos.push_back(nums[i] * nums[i]);
        }

        // Negative squares are in decreasing order
        reverse(neg.begin(), neg.end());

        int i = 0, j = 0;

        // Merge two sorted arrays
        while(i < neg.size() && j < pos.size()) {
            if(neg[i] <= pos[j]) {
                res.push_back(neg[i]);
                i++;
            } else {
                res.push_back(pos[j]);
                j++;
            }
        }

        while(i < neg.size()) {
            res.push_back(neg[i]);
            i++;
        }

        while(j < pos.size()) {
            res.push_back(pos[j]);
            j++;
        }

        return res;
    }
};