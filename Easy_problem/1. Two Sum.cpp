class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        int left;
        for(int i = 0; i < nums.size(); i++){
            index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            left = target-nums[i];
            if(index.count(left)&&index[left]!=i)return {i, index[left]};
        }
        return {};
    }
};
