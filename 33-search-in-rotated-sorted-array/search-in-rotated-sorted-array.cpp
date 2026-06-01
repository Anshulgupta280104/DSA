class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == key)
                return mid;

            // Left half is sorted
            if (arr[l] <= arr[mid]) {
                if (key >= arr[l] && key < arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // Right half is sorted
            else {
                if (key > arr[mid] && key <= arr[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};