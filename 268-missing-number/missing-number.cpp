class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // -------- Bubble Sort --------
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    // swap
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        // -------- Find Missing Number --------
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        // If all numbers 0..n-1 are present, answer is n
        return n;
    }
};
