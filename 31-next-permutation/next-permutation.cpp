class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find pivot index from the right
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // find smallest greater element than the pivot and swap it
        if (pivot != -1) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }
        // if there are no pivot, then we will directly sort the arr, above condition will be skipped
        // reverse the suffix, means elements after the pivot
        int left = pivot + 1;
        int right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};