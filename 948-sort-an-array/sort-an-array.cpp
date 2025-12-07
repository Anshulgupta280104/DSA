class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Extract elements one by one from heap
        for (int i = n - 1; i > 0; i--) {
            // Move root (max) to end
            swap(nums[0], nums[i]);

            // Call heapify on reduced heap
            heapify(nums, i, 0);
        }

        return nums;
    }

private:
    void heapify(vector<int>& nums, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && nums[left] > nums[largest])
            largest = left;

        if (right < size && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, size, largest);
        }
    }
};
