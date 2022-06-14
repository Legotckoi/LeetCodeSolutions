class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::map<int, int> targets;
        
        for (int i = 0; i < n; ++i)
        {
            if (targets.count(nums[i]) && targets[nums[i]] != i)
            {
                return {targets[nums[i]], i};
            }
            targets[target - nums[i]] = i;
        }
        
        return {};
    }
};
