class Solution {
public:
    int sum_vector(vector<int>& nums, bool set) {
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++) { 
            if(set and i > 0 and nums[i] == nums[i-1]) continue;  
            res += nums[i];
        }
        
        return res;
    }
    
    int sum(int n) {
        int res = 0;
        
        for(int i = 1; i < n+1; i++) res += i;
        
        return res;
    }
    
    vector<int> findErrorNums(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        int total = sum_vector(nums, false), unique = sum_vector(nums, true);
        vector<int> result;
        result.push_back(total - unique);
        result.push_back(sum(length) - unique);
        return result;
    }
};
