class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = 0;
        int minlen = INT_MAX;
        int sum = 0;
        while(right < n){
            sum += nums[right];
            while(left <= right && sum >= target){
                minlen = min(right-left+1,minlen);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(minlen == INT_MAX){
            return 0;
        }
        return minlen;
    }
};