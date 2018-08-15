class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> occurredAtIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (occurredAtIndex.count(target - nums[i])) {
                return {occurredAtIndex[target - nums[i]], i};
            }
            occurredAtIndex[nums[i]] = i;
        }
    }
};
