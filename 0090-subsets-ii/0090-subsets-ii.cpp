class Solution {
public:
    void getAllSub(vector<int>& nums, vector<int>& allSubsets, int i,
                   vector<vector<int>>& ans) {

        // base case
        if (i == nums.size()) {
            ans.push_back(allSubsets);
            return;
        }

        // main function

        // Case-1 Inclusion
        allSubsets.push_back(nums[i]);
        getAllSub(nums, allSubsets, i + 1, ans);
        allSubsets.pop_back();

        // Case-2 Exclusion
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        getAllSub(nums, allSubsets, idx, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> allSubsets;
        vector<vector<int>> ans;

        getAllSub(nums, allSubsets, 0, ans);
        return ans;
    }
};