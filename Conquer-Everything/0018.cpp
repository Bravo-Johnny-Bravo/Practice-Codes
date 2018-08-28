class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int ptr1 = j + 1;
                int ptr2 = (int) nums.size() - 1;
                int need = target - (nums[i] + nums[j]);
                while (ptr1 < ptr2) {
                    int sum = nums[ptr1] + nums[ptr2];
                    if (sum == need) {
                        ans.push_back({nums[i], nums[j], nums[ptr1], nums[ptr2]});
                    }
                    if (sum <= need) {
                        ptr1++;
                        while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1 - 1]) {
                            ptr1++;
                        }
                    } else {
                        ptr2--;
                        while (ptr1 < ptr2 && nums[ptr2] == nums[ptr2 + 1]) {
                            ptr2--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
