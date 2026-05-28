class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        double sum=0;
        double maxavg=0.0;
        while(right<n){
            sum+=nums[right];
            while((right-left+1)==k){
                double avg=sum/k;
                maxavg=max(avg,maxavg);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        return maxavg;
    }
};